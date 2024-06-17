#include <Magnum/Math/Color.h>
#include <iostream>
#include <sol/sol.hpp>

int main()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);
    using Vec3D = Magnum::Vector3;
    Vec3D vec{0, 1, 0};
    std::cout << vec.x() << " " << vec.y() << " " << vec.z() << std::endl;

    sol::usertype<Vec3D> vec1_typ = lua.new_usertype<Vec3D>("Vec1D", sol::constructors<Vec3D()>());
    vec1_typ["x"] = &Vec3D::x;

    return 0;
}
