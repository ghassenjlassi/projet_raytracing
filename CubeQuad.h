/*
 * CubeQuad.h
 *
 *  Created on: 27 déc. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */
#ifndef CUBEQUAD_H_
#define CUBEQUAD_H_
#include "Shape.h"
#include "Vector3f.h"

class CubeQuad : public Shape{ // @suppress("Class has a virtual method and non-virtual destructor")
	public:
		CubeQuad();
		   /**
			* @return CubeQuad : New instance of CubeQuad
			*/
		CubeQuad(Material m, Vector3f origin, Vector3f width, Vector3f height);

	private:

		Vector3f origin_;
		Vector3f width_;
		Vector3f height_;
	public:
	   /**
		* @return Vector3f  : The origin of the cube quad
		*/
		Vector3f getOrigin() const { return origin_; }
		/**
		 * @return Vector3f : The Width of the Cube quad intercepted
		 */
		Vector3f getWidth() const { return width_; }
		/**
   	     * @return Vector3f : The Height of the Cube quad intercepted
		 */
		Vector3f getHeight() const { return height_; }

	public:
		/**
				* @brief Find if there's an intersection between an object and a ray
				*
				* @details Find if there's an intersection between an object and a ray and
				* give intersect of ray3f: the value of the  distance from ray's origin to the point of intersection
				* @param ray Ray3f
				* @return  bool true if we have intersection
				*/
		virtual bool is_hit(Ray3f &ray);
		/**
				* @brief Give the reflection ray of another ray that hit an object
				* @details Give the reflection ray from the intersection position
				* @param ray Ray3f
				* @return Ray3f : the reflected ray
				*/
		virtual Ray3f reflect(Ray3f ray);
		/**
				* @brief Find the intersection position between an object and a ray
				* @details give the intersection position if there's an intersection
				* return -1 if there's no intersection
				* @param ray Ray3f
				* @return  double the distance from our ray origin to the point of intersection
				*  return -1 if there's no intersection
				*/
		virtual double Intersection(Ray3f ray);
		/**
				* @brief Find the normal vector of an object
				* @details give the normal vector from a position
				* @param ray Vector3f
				* @return  Vector3f: the normal vector
				*/
		virtual Vector3f getNormal(Vector3f position){
			Vector3f N =(width_.crossProduct(height_)).normalize();
			return N;
		}
};


#endif /* CUBEQUAD_H_ */
