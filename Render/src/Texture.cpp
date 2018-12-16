#include "Texture.hpp"
#include <iostream>

using namespace glimac

GLuint Texture::getId(){
	return m_id;
}

Texture::loadTexture(std::string Filepath) // TO DO : changer la fonction pour que ça marche pour plusieurs textures 
{
	m_image = loadImage(Filepath);

	if (m_image == nullptr){
		std::cout << " Problème lors du chargement de la texture" << std::endl;
	}
	glGenTextures(1, &m_id);
	bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image->getWidth(), m_image->getHeight(), 0, GL_RGBA, GL_FLOAT, m_image->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_FILTER, GL_LINEAR);
	unbind();
}

Texture::Texture(std::string FilePath)
{
	try{
		loadTexture(Filepath);
	}
	catch (const std::string &e){
		std::cout << "Erreur : " << e << std::endl;
	}
}

void Texture::unbind(){
        glActiveTexture(m_format);
        glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::bind(){
        glActiveTexture(m_format);
        glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::free(){
	 glDeleteTextures(1, &m_id);
}