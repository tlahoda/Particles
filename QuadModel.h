/**
 * \file QuadModel.h. Contains the QuadModel class.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef PARTICLE_QUADMODEL_H
#define PARTICLE_QUADMODEL_H

#include "gl/Primitive.h"

namespace particle {
    /**
     * \class QuadModel, Draws a quad centered on the particle's origin.
     */
    class QuadModel {
        public:
            /**
             * \typedef gl::Quads glType,
             *          The primitive type.
             */
            typedef gl::Quads glType;

            /**
             * Renders a quad centered on the particle's origin.
             *
             * \tparam Particle, The type of the particle.
             *
             * \param particle const Particle&, The particle for which to render the quad.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (const Particle& particle) const {
                float x = particle.position ()[0];
                float y = particle.position ()[1];
                float z = particle.position ()[2];
                float size = 1.0f;
 
                //glColor3ub(150, 90, 50);
 
                glColor3f (1.0f, 0.0f, 0.0f);
 
                //glTexCoord2f (0.0f, 1.0); 
                glVertex3f (x + size, y + size, z);
 
                //glTexCoord2f (0.0f, 0.0); 
                glVertex3f (x - size, y + size, z);
 
                //glTexCoord2f (1.0f, 0.0); 
                glVertex3f (x - size, y - size, z);
 
                //glTexCoord2f (1.0f, 1.0); 
                glVertex3f (x + size, y - size, z);
            };
    }; //QuadModel
}; //particle

#endif //PARTICLE_QUADMODEL_H

