#include "Vector4.h"
#include <cmath>
namespace RareEngine
{
    Vector4::Vector4(Dimention d,float x,float y ,float z,float w )
    {
      
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        
        this->dimention = d;
        change = true;
    }
    Vector4::Vector4(float x,float y ,float z,float w )
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        
        change = true;
    }
    float Vector4::X()
    {
        return x;
    }

    float Vector4::Y()
    {
        return y;
    }

    float Vector4::Z()
    {
        return z;
    }

    float Vector4::W()
    {
        return w;
    }

    void Vector4::X(float value)
    {
        
        if (x != value)
        {
            x = value;
            change = true;
        }
    }

    void Vector4::Y(float value)
    {
        if (y != value)
        {
            y = value;
            change = true;
        }
    }

    void Vector4::Z(float value)
    {
        if(dimention == TWO_D)return;
        if (z != value)
        {
            z = value;
            change = true;
        }
    }

    void Vector4::W(float value)
    {
        if(dimention == TWO_D||dimention == THREE_D)return;
        if (w != value)
        {
            w = value;
            change = true;
        }
    }
    float Vector4::glR(){
        return x/255.0f;
    }
    float Vector4::glG(){
        return y/255.0f;
    }
    float Vector4::glB(){
        return z/255.0f;
    }
    float Vector4::glA(){
        return w/255.0f;
    }
    float Vector4::R(){
        return x;
    }
    float Vector4::G(){
        return y;
    }
    float Vector4::B(){
        return z;
    }
    float Vector4::A(){
        return w;
    }
    void Vector4::R(float r){
        X(r);
    }
    void Vector4::G(float g){
        Y(g);
    }
    void Vector4::B(float b){
        Z(b);
    }
    void Vector4::A(float a){
        W(a);
    }
    bool Vector4::DataChanged()
    {
        return change;
    }


    Vector4 Vector4::operator+(const Vector4& other) const
    {
        Vector4 result = *this;
        if (dimention != other.dimention)
        return result;
        result.X(result.X() + other.x);
        result.Y(result.Y() + other.y);
        result.Z(result.Z() + other.z);
        result.W(result.W() + other.w);

        return result;
    }

    Vector4 Vector4::operator-(const Vector4& other) const
    {
        Vector4 result = *this;
        if (dimention != other.dimention)
        return result;
        result.X(result.X() - other.x);
        result.Y(result.Y() - other.y);
        result.Z(result.Z() - other.z);
        result.W(result.W() - other.w);

        return result;
    }

    Vector4 Vector4::operator*(const Vector4& other) const
    {
        Vector4 result = *this;
        if (dimention != other.dimention)
        return result;
        result.X(result.X() * other.x);
        result.Y(result.Y() * other.y);
        result.Z(result.Z() * other.z);
        result.W(result.W() * other.w);

        return result;
    }

    Vector4 Vector4::operator/(const Vector4& other) const
    {
        Vector4 result = *this;
        if (dimention != other.dimention)
        return result;
        result.X(result.X() / other.x);
        result.Y(result.Y() / other.y);
        result.Z(result.Z() / other.z);
        result.W(result.W() / other.w);

        return result;
    }


    bool Vector4::operator==(const Vector4& other) const
    {
        if (dimention != other.dimention)
        return false;
        return x == other.x &&
               y == other.y &&
               z == other.z &&
               w == other.w;
    }


    Vector4 Vector4::operator+(float other) const
    {
        Vector4 result = *this;
        
        result.X(result.X() + other);
        result.Y(result.Y() + other);
        result.Z(result.Z() + other);
        result.W(result.W() + other);

        return result;
    }

    Vector4 Vector4::operator-(float other) const
    {
        Vector4 result = *this;
        
        result.X(result.X() - other);
        result.Y(result.Y() - other);
        result.Z(result.Z() - other);
        result.W(result.W() - other);

        return result;
    }

    Vector4 Vector4::operator*(float other) const
    {
        Vector4 result = *this;
        
        result.X(result.X() * other);
        result.Y(result.Y() * other);
        result.Z(result.Z() * other);
        result.W(result.W() * other);

        return result;
    }

    Vector4 Vector4::operator/(float other) const
    {
        Vector4 result = *this;
        
        result.X(result.X() / other);
        result.Y(result.Y() / other);
        result.Z(result.Z() / other);
        result.W(result.W() / other);

        return result;
    }


    Vector4& Vector4::operator+=(const Vector4& other)
    {
        if (dimention != other.dimention)
        return *this;
        X(X() + other.x);
        Y(Y() + other.y);
        Z(Z() + other.z);
        W(W() + other.w);

        return *this;
    }

    Vector4& Vector4::operator-=(const Vector4& other)
    {
        if (dimention != other.dimention)
        return *this;
        X(X() - other.x);
        Y(Y() - other.y);
        Z(Z() - other.z);
        W(W() - other.w);

        return *this;
    }

    Vector4& Vector4::operator*=(const Vector4& other)
    {
        if (dimention != other.dimention)
        return *this;
        X(X() * other.x);
        Y(Y() * other.y);
        Z(Z() * other.z);
        W(W() * other.w);

        return *this;
    }

    Vector4& Vector4::operator/=(const Vector4& other)
    {
        if (dimention != other.dimention)
        return *this;
        X(X() / other.x);
        Y(Y() / other.y);
        Z(Z() / other.z);
        W(W() / other.w);

        return *this;
    }


    Vector4& Vector4::operator+=(float other)
    {
        
        X(X() + other);
        Y(Y() + other);
        Z(Z() + other);
        W(W() + other);

        return *this;
    }

    Vector4& Vector4::operator-=(float other)
    {
        X(X() - other);
        Y(Y() - other);
        Z(Z() - other);
        W(W() - other);

        return *this;
    }

    Vector4& Vector4::operator*=(float other)
    {
        X(X() * other);
        Y(Y() * other);
        Z(Z() * other);
        W(W() * other);

        return *this;
    }

    Vector4& Vector4::operator/=(float other)
    {
        X(X() / other);
        Y(Y() / other);
        Z(Z() / other);
        W(W() / other);

        return *this;
    }
    void Vector4::ResetDataChangedFlag(){
        change = false;
    }
  void Vector4::Set(float x,float y,float z,float w){
    Set(x,y,z);W(w);
  }
  void Vector4::Set(float x,float y,float z){
    Set(x,y);Z(z);
  }
  void Vector4::Set(float x,float y){
    X(x);Y(y);
  }
  float Vector4::Dot2D(Vector4* to){
    return (X()*to->X())+(Y()*to->Y());
  }
  float Vector4::Dot3D(Vector4* to){
    return (X()*to->X())+(Y()*to->Y())+(Z()*to->Z());
  }
  float Vector4::Cross2D(Vector4* to){
    return (X()*to->Y())-(Y()*to->X());
  }
  Vector4* Vector4::Cross3D(Vector4* to){//yz-zy,zx-xz,xy-yx
    return new Vector4(THREE_D,(Y()*to->Z())-(Z()*to->Y()),(Z()*to->X())-(X()*to->Z()),(X()*to->Y())-(Y()*to->X()));
  }
  float Vector4::Distance2D(Vector4* to){
    return std::sqrt(std::pow(to->X()-X(),2)+std::pow(to->Y()-Y(),2));
  }
  float Vector4::Distance3D(Vector4* to){
    return std::sqrt(std::pow(to->X()-X(),2)+std::pow(to->Y()-Y(),2)+std::pow(to->Z()-Z(),2));
  }
  Vector4::~Vector4(){
    //delete *x;delete *y;delete *z;delete *w;delete *dimention;delete *change;
  }
  void Vector4::Set(Vector4* to){
    X(to->X());
    Y(to->Y());
    Z(to->Z());
    W(to->W());
  }
    void Vector4::Set(Vector4 to){
    X(to.X());
    Y(to.Y());
    Z(to.Z());
    W(to.W());
    }
  void Vector4::Normalize2D(){
    float factor = std::sqrt(X()*X()+Y()*Y());
    if(factor==0)return;
    (*this)/=factor;
  }
  void Vector4::Normalize3D(){
    float factor = std::sqrt(X()*X()+Y()*Y()+Z()*Z());
    if(factor==0)return;
    (*this)/=factor;
  }
}
