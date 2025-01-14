/**
 * \file Texture.hpp
 * \brief Decalaration of the class "Texture"
 */

#ifndef __TEXTURE__HPP
#define __TEXTURE__HPP

#include <iostream>
#include <glimac/Shader.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <SDL/SDL.h>

#include <Error/Error.hpp>

using namespace glimac;

class Texture {
private:
  FilePath m_path; /*!< Path of the file of the texture */
  GLuint m_id; /*!< id of the texture */
  std::unique_ptr<Image> m_image; /*!< pointer to the image of the texture */
  GLenum m_format; /*!< format of the texture */
  const int m_minFilter; /*!< minimum filter of the texture */
  const int m_maxFilter; /*!< maximum filter of the texture  */

public:
  /**
   * \brief constructor of Texture 
   */
  Texture() = default;

  /**
   * \brief method that loads the texture 
   */
  void loadTexture();

  /**
   * \brief constructor of Texture using a Filepath
   * \param v : Filepath of the file with textures
   */

  Texture(FilePath path);

  /**
   * \brief constructor of Texture using a path, a maxFilter and a minFilter 
   * \param v : Filepath of the file, minFilter and maxFilter
   */

  Texture(FilePath path, const int min, const int max);

  /**
   * \brief destructor of Texture
   */
  ~Texture() {
  };

  /**
   * \brief getter of the Image that we will draw with Texture
   * \return : the pointer that leads us to the Image
   * pas besoin car la methode loadImage existe déjà dans glimac et on peut l'utiliser
   */
  std::unique_ptr<Image> getImage();

  /**
   * \brief method that binds the Texture 
   */
  void bind();

  /**
   * \brief method that debinds the Texture 
   */
  void debind();

  /**
   * \brief getter of the id of the Texture 
   * \return : the id of the texture 
   */
  GLuint getId();

  /**
   * \brief methods that free the memory allocated to the texture after using it
   */
  void free();

  /**
   * \brief Opérateur << for print texture data
   */
  friend std::ostream &operator<<(std::ostream &os, const Texture &tex) {
    os << "  -- path = \"" << tex.m_path << "\"\n";
    os << "  -- id = " << tex.m_id << "\n";
    os << "  -- format = " << tex.m_format << "\n";
    os << "  -- image = " << tex.m_image->getWidth() << " x " << tex.m_image->getHeight() << "\n";
    return os;
  }
};

#endif