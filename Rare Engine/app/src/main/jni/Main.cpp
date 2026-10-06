/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <map>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <atomic>
#include <GLES3/gl3.h>
#include "Renderer.h"
#include "Engine.h"
#include "Behaviour.h"
#include "GameObject.h"
#include "Scene.h"
#include <thread>
class TestBehaviour : public RareEngine::Behaviour{
  public:
  void OnEveryFrame(float delta)override{
  
    if(MyGameObject->MyScene())MyGameObject->MyScene()->backgroundColor->Set(255,0,0,255);// red,green,blue,alpha
    
    //RareEngine::Engine::Log("Scene Exist");
  }
};
extern "C"
{
    std::map<int,int> rep;
    std::map<int,EGLContext> dContext;
    std::map<int,RareEngine::Renderer*> renderers;
    std::map<int,ANativeWindow*> windows;
    std::map<int,std::atomic<bool>> running;
    std::map<int, std::atomic<int>> surfaceWidths;
    std::map<int, std::atomic<int>> surfaceHeights;
    std::map<int,std::thread> rendererThreads;
    int renderercount = 0;
	JNIEXPORT jstring JNICALL Java_RareEngine_android_JniAttachment_helloFromJNI(JNIEnv* env, jobject thiz)
	{
        const char* text = R"(
        hi
        hello from jni
        )";
		return env->NewStringUTF(text);
	}
    JNIEXPORT jint JNICALL Java_RareEngine_android_JniAttachment_setUpGLSurface(JNIEnv* env,jobject thiz,jobject surface,jint sid){
     // if (rendererThreads[sid].joinable()) {
        
        
        ANativeWindow* window = ANativeWindow_fromSurface(env,surface);
        if(window == nullptr){
            return -1;
        }
      int pid = static_cast<int>(sid);
      
      RareEngine::Renderer* renderclass = nullptr;
      if(renderers[pid]!=nullptr){
        RareEngine::Engine::Log("Rare Engine: Using Old Renderer");
        rep[renderercount] = pid;
      renderclass  = renderers[sid];
        
      }else{
        RareEngine::Engine::Log("Rare Engine: Creating Renderer");
        
      renderclass  =  new RareEngine::Renderer();
        
      }
      renderers[renderercount]=renderclass;
        windows[renderercount]=window;
        running[renderercount] = true;
        surfaceWidths[renderercount] = 0;
        surfaceHeights[renderercount] = 0;
        return renderercount++;
    }
    
    JNIEXPORT void JNICALL Java_RareEngine_android_JniAttachment_destroyRenderer(JNIEnv* env,jobject thiz,jint surfaceid){
        running[surfaceid] = false;
      
      RareEngine::Engine::LogW("Surface Destroy called\n(it may create bugs)");
    }
    JNIEXPORT void JNICALL Java_RareEngine_android_JniAttachment_onSurfaceChanged(JNIEnv* env,jobject thiz,jint surfaceid,jint width,jint height){
        surfaceWidths[surfaceid] = width;
        surfaceHeights[surfaceid] = height;
    }
    JNIEXPORT void JNICALL Java_RareEngine_android_JniAttachment_runTestScene(JNIEnv* env,jobject thiz,jint surfaceid){
      
        RareEngine::Scene* scene = new RareEngine::Scene();
        //scene->backgroundColor->R(255);
        RareEngine::GameObject* testObj = new RareEngine::GameObject();
        TestBehaviour* tb = new TestBehaviour();
        testObj->AddBehaviour(tb);
        scene->AddObject(testObj,RareEngine::Scene::OBJECTS_LAYER);
        if(renderers[surfaceid]!=nullptr)
        renderers[surfaceid]->SetCurrentScene(scene);
    }
  /*JNIEXPORT jstring JNICALL Java_RareEngine_android_JniAttachment_getLog(JNIEnv* env,jobject thiz){
      return env->NewStringUTF(RareEngine::Engine::GetLog().c_str());
    }*/
  JNIEXPORT jstring JNICALL
Java_RareEngine_android_JniAttachment_getLog(
    JNIEnv* env,
    jobject thiz)
{
    std::string s = RareEngine::Engine::GetLog();
  
    return  env->NewStringUTF(s.c_str());
}
    JNIEXPORT void JNICALL Java_RareEngine_android_JniAttachment_startRenderer(JNIEnv* env,jobject thiz,jint surfaceid){
        
        rendererThreads[surfaceid]=std::thread([surfaceid]{
            ANativeWindow* win = windows[surfaceid];
            RareEngine::Renderer* renderer = renderers[surfaceid];
            EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);//GET ANDROID DISPLAY
            if(display == EGL_NO_DISPLAY)return;//check valid display
            if(!eglInitialize(display,nullptr,nullptr))return;//initialize egl
            const EGLint configAttribs[] = {//requirements
                EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT_KHR,
                EGL_SURFACE_TYPE, EGL_WINDOW_BIT,

                EGL_RED_SIZE, 8,
                EGL_GREEN_SIZE, 8,
                EGL_BLUE_SIZE, 8,
                EGL_ALPHA_SIZE, 8,

                EGL_DEPTH_SIZE, 24,

                EGL_NONE
            };
            EGLConfig config;
            EGLint numConfigs;
            if(!eglChooseConfig(display,configAttribs,&config,1,&numConfigs))return;//gets config and number of config with requirement
            
            const EGLint contextAttribs[] = {//context requirement
                EGL_CONTEXT_CLIENT_VERSION, 3,
                EGL_NONE
            };
            EGLContext context;
          if(rep.find(surfaceid)!=rep.end()){
            RareEngine::Engine::LogW("Using old context");
            context = dContext[rep[surfaceid]];
          }else{
            RareEngine::Engine::LogW("Using new context");
            context = eglCreateContext(display,config,EGL_NO_CONTEXT,contextAttribs);//create context
          }
            if(context == EGL_NO_CONTEXT)return;//check for valid context
            
            EGLSurface eglSurface = eglCreateWindowSurface(display,config,win,nullptr);//create eglsurface
            if(eglSurface == EGL_NO_SURFACE)return;//check eglsurface validity
            
            if(!eglMakeCurrent(display,eglSurface,eglSurface,context))return;//make created egl context current
            
            //getting rendering area width and height
            EGLint width,height;
            eglQuerySurface(display,eglSurface,EGL_WIDTH,&width);
            eglQuerySurface(display,eglSurface,EGL_HEIGHT,&height);
            surfaceWidths[surfaceid] = width;
            surfaceHeights[surfaceid] = height;
            
            //call renderer methods to start
            renderer->OnSurfaceCreated();
            renderer->OnSurfaceChanged(width,height);
            //RareEngine::Engine::Log("Rare Engine: Surface Setup Sucess");
            while(running[surfaceid]){
                if(surfaceWidths[surfaceid] != width || surfaceHeights[surfaceid] != height){
                    width = surfaceWidths[surfaceid] ;
                    height = surfaceHeights[surfaceid] ;
                    renderer->OnSurfaceChanged(width,height);
                }
                renderer->OnDrawFrame();
                
                eglSwapBuffers(display, eglSurface);//exchange buffer in surface and buffer we have
            }
          
            eglMakeCurrent(
                display,
                EGL_NO_SURFACE,
                EGL_NO_SURFACE,
                EGL_NO_CONTEXT
            );//relive current context from our context

            eglDestroySurface(display, eglSurface);//destroy the surface
            dContext[surfaceid]=context;//destroy the contex5
            //eglTerminate(display);//end the egl
            ANativeWindow_release(win);//release the window
        });rendererThreads[surfaceid].detach();
    }
}
