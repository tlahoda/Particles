/**
 * \file VertexModel.h, Contains the VertexModel class.
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
#ifndef PARTICLE_VERTEXMODEL_H
#define PARTICLE_VERTEXMODEL_H

#include "gl/Primitive.h"

namespace particle {
    /**
     * \class VertexModel, Draws a vertex for a primitive.
     *
     * \tparam GlType, The type of the primitive.
     */
    template<class GlType>
    class VertexModel {
        public:
            /**
             * \typedef GlType glType,
             *          The primitive type.
             */
            typedef GlType glType;

            /**
             * Renders a vertex for a primitive.
             *
             * \tparam Particle, The type of the particle.
             *
             * \param particle const Particle&, The particle to render.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (const Particle& particle) const {
                glColor3f (1.0f, 0.0f, 0.0f);

                //glTexCoord2f (0.0f, 1.0); 
                glVertex3f (particle.position ()[0],
                            particle.position ()[1],
                            particle.position ()[2]);
            };
    }; //VertexModel
}; //particle

#endif //PARTICLE_VERTEXMODEL_H

