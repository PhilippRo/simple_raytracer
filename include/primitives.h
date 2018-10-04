#pragma once

#include <vec3.h>
#include <gfx.h>

using namespace math::vector;

namespace primitives{

///
/// \brief Material Class to define Surface Properties of Polygons
///

class material{

public:
    ///
    /// \brief Constructor to create black Material
    ///
     material();

     ///
     /// \brief Constructor to create Material with Color
     /// \param _col Color of the Material
     ///
     material(color _col);

     ///
     /// \brief Constructor to create Material with color and non-standard refractive properties
     /// \param _col Color of the Material
     /// \param _refrac Index of Refraction of the Material
     ///
     material(color _col, float _refrac);

private:
    color col;
    float alpha;
    float refrac;

};

  namespace polygons{

  ///
  /// \brief Triangle Class. Stores Information about 3D Triangle
  ///

    class triangle{

    public:

        ///
        /// \brief Constructor to create Triangle with all Points in (0, 0, 0)
        ///
      triangle();

      ///
      /// \brief Constructor to create Triangle with three Points given
      /// \param _a Vector to Point A
      /// \param _b Vector to Point B
      /// \param _c Vector to Point C
      ///
      triangle(vec3 _a, vec3 _b, vec3 _c);

      ///
      /// \brief Modify the Points of the Triangle
      /// \param _a New Vector to Point A
      /// \param _b New Vector to Point B
      /// \param _c New Vector to Point C
      ///
      void set_points(vec3 _a, vec3 _b, vec3 _c);

      ///
      /// \brief Assign Material to Triangle
      /// \param _mat Material to define Surface Properties
      ///
      void set_material(material _mat);

      ///
      /// \brief Returns Current Material of the Triangle
      /// \return material Material of the Triangle
      ///
      material get_material();

      ///
      /// \brief Access to Point A
      /// \return vec3 Vector to Point A of Triangle
      ///
      vec3 get_a();

      ///
      /// \brief Access to Point B
      /// \return vec3 Vector to Point B of Triangle
      ///
      vec3 get_b();

      ///
      /// \brief Access to Point C
      /// \return vec3 Vector to Point C of Triangle
      ///
      vec3 get_c();

      ///
      /// \brief Returns Normal Vector of the Triangle Plane
      /// \return vec3 Normal Vector
      ///
      vec3 get_norm();

      ///
      /// \brief Returns Point in Plane to define Triangle Plane
      /// \return vec3 Vector to Point in Plane
      ///
      vec3 get_support();

    private:

      vec3 a, b, c;
      vec3 normal;
      vec3 support;

      material mat;
    };
  }
}
