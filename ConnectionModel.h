/**
 * \file ConnectionModel.h, Contains the ConnectionModel class.
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
#ifndef PARTICLE_CONNECTIONMODEL_H
#define PARTICLE_CONNECTIONMODEL_H

#include "gl/Primitive.h"

namespace particle {
    /**
     * \class ConnectionModel, Draws a vertex for a primitive.
     *
     * \param GlType, The type of the primitive.
     */
    class ConnectionModel {
        public:
            /**
             * \typedef GlType glType,
             *          The type of the primitive.
             */
            typedef gl::Lines glType;

            /**
             * Renders a vertex for a primitive.
             *
             * \param Particle, The type of the particle.
             *
             * \param particle const Particle&, The particle to render.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (const Particle& particle) const {
                glColor3f (1.0f, 0.0f, 0.0f);

                glVertex3f (constraint->connection ().first ().position ()[0],
                            constraint->connection ().first ().position ()[1],
                            constraint->connection ().first ().position ()[2]);
                
                glVertex3f (constraint->connection ().second ().position ()[0],
                            constraint->connection ().second ().position ()[1],
                            constraint->connection ().second ().position ()[2]);
            };
    }; //ConnectionModel
}; //particle

#endif //PARTICLE_CONNECTIONMODEL_H

