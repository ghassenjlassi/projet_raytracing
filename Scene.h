/*
 * Scene.h
 *
 *  Created on: 27 d�c. 2017
 *      Author: Ghassen_jlassi&Khalil_abid
 */

#ifndef SCENE_H_
#define SCENE_H_
#include "Shape.h"
#include "Camera.h"
#include <fstream>
#include <vector>
using namespace std;
class Scene {
private:
	Camera camera_;
    vector<Shape*> shapes_;
	Ray3f source_ ;
public:
	Scene(Camera c, vector<Shape*> s, Ray3f r);
	/**
	@brief Scene getter
	*/
	Camera getCamera() const {return this->camera_;}

	vector<Shape*> getShapes() const {return this->shapes_;}

	Ray3f getSource() const {return this->source_;}
	/**
	* @param filename char* (string)
	* @param width int
	* @param height int
	* @param dpi int
	* @param data Material* a table that contains the color of the pixels
	* @return  void but saves a png file
	*/
	void save (const char *filename, int w, int h, int dpi, Material *couleur);
	/**
	* @brief Get the color of the intersection
	* @param Ray3f intercepted
	* @param object_index int
	* @param accuracy double
	* @return  Material
	*/
	Material getColor(Ray3f ray,int object_index);
	/**
	* @brief Render the scene
	* @param filename char* (string)
	* @param width int
	* @param height int
	* @return void
	*/
	void render(int width,int height,char* filename);
	~Scene();
};
#endif /* SCENE_H_ */
