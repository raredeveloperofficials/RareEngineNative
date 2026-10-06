#pragma once
namespace RareEngine{
    class Vector4{
        private:
        
        float x,y,z,w;
        bool change;
        public:
      ~Vector4();
        enum Dimention{
            TWO_D,THREE_D,FOUR_D,COLOR_D
        };
        Dimention dimention = FOUR_D;
        Vector4(Dimention d = FOUR_D,float x = 0, float y = 0, float z = 0, float w = 0);
        Vector4(float x, float y , float z , float w );
      
        float X();
        float Y();
        float Z();
        float W();
        float R();
        float G();
        float B();
        float A();
        float glR();
        float glG();
        float glB();
        float glA();
        
        void X(float x);
        void Y(float y);
        void Z(float z);
        void W(float W);
        void R(float r);
        void G(float g);
        void B(float b);
        void A(float a);
        bool DataChanged();
        void ResetDataChangedFlag();
        Vector4 operator+(const Vector4& other)const;
        Vector4 operator-(const Vector4& other)const;
        Vector4 operator*(const Vector4& other)const;
        Vector4 operator/(const Vector4& other)const;
        bool operator==(const Vector4& other)const;
        
        Vector4 operator+(float other)const;
        Vector4 operator-(float other)const;
        Vector4 operator*(float other)const;
        Vector4 operator/(float other)const;
        
        Vector4& operator+=(const Vector4& other);
        Vector4& operator-=(const Vector4& other);
        Vector4& operator*=(const Vector4& other);
        Vector4& operator/=(const Vector4& other);
        
        
        Vector4& operator+=(float other);
        Vector4& operator-=(float other);
        Vector4& operator*=(float other);
        Vector4& operator/=(float other);

        void Set(float x,float y,float z,float w);
        void Set(float x,float y,float z);
        void Set(float x,float y);

      float Dot2D(Vector4* to);
      float Dot3D(Vector4* to);
      float Cross2D(Vector4* to);
      Vector4* Cross3D(Vector4* to);

      float Distance2D(Vector4* to);
      float Distance3D(Vector4* to);

      void Set(Vector4* to);
      void Set(Vector4 to);
      void Normalize2D();
      void Normalize3D();
    };
}
