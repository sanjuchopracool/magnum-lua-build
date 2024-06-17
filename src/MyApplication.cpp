#include <Magnum/Math/Color.h>
#include <iostream>
#include <sol/sol.hpp>

// Small example class  similar to magnum vector2
template<std::size_t size, class T>
class MyVector
{
protected:
    T _data[size];
};

template<typename T>
class MyVector2 : public MyVector<2, T>
{
public:
    T &x() { return MyVector<2, T>::_data[0]; }
    T &y() { return MyVector<2, T>::_data[1]; }
};

int main()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);

    using MyVec2D = MyVector2<float>;
    MyVec2D myvec;
    // MyVector2 compiles fine
    sol::usertype<MyVec2D> vec3_typ = lua.new_usertype<MyVec2D>("MyVec3D",
                                                                sol::constructors<MyVec2D()>());
    vec3_typ["x"] = &MyVec2D::x;

    // magnum vector 2 does not compile
    using Vec2D = Magnum::Vector2;
    Vec2D vec{0, 1};
    std::cout << vec.x() << " " << vec.y() << " " << std::endl;
    sol::usertype<Vec2D> vec2_typ = lua.new_usertype<Vec2D>("Vec2D", sol::constructors<Vec2D()>());

    // This line give error
    vec2_typ["x"] = &Vec2D::x;

    return 0;
}
