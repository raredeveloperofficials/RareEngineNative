#pragma once
#include "GraphicsBackend.h"
#include <atomic>
#include <mutex>
namespace RareEngine{
    class Engine{
        private:
        static std::string logs;
  
      static std::atomic<bool> clear;
        public:
        static GraphicsBackend* Graphics;
        static void Log(const std::string& lg)
{
  if(clear){Engine::logs.clear();clear = false;}
Engine::logs += lg;
Engine::logs += '\n';
}
        

        static void LogR(const std::string& lg)
        {
            Log("Rare Engine: "+std::string(lg));
        }
        
        static void LogW(const std::string& lg)
        {
           Log("Warning: "+std::string(lg));
        }
        
        static void LogE(const std::string& lg)
        {
            Log("Error: "+std::string(lg));
        }
        static std::string GetLog()
{
    
    std::string s = std::move(Engine::logs);
    clear = true;

    return  s;
}
        
    };
}
