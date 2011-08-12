/**
 * \file Connection.h, Contains the Connection class.
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
#ifndef PARTICLE_CONNECTION_H
#define PARTICLE_CONNECTION_H

#include <boost/numeric/ublas/vector.hpp>

#include "particles/common.h"

namespace particle {
    /**
     * \class Connection, Models a connection between two particles.
     *
     * \tparam Particle, The type of the particles in the connection.
     */
    template<class Particle>
    class Connection {
        public:
            /**
             * \typedef Particle particle,
             *          The particle type.
             */
            typedef Particle particle;

            /**
             * Constructs an empty connection.
             */
            Connection ()
              : particles_ (std::pair<Particle*, Particle*> (0, 0)) {};

            /**
             * Constructs a connection btween the given particles.
             *
             * \param first Particle*, The first particle of the connection.
             * \param second Particle*, The second particle of the connection.
             */
            Connection (Particle* first, Particle* second)
              : particles_ (std::make_pair (first, second)) {};

            /**
             * The first particle of the connection.
             *
             * \return Particle&, The first particle.
             */
            Particle& first () { return *particles_.first; };
            
            /**
             * The second particle of the connection.
             *
             * \return Particle&, The second particle.
             */
            Particle& second () { *particles_.second; };

        private:
            /**
             * The particles in the connection.
             */
            std::pair<Particle*, Particle*> particles_;
    }; //Connection
}; //particle

#endif //PARTICLE_CONNECTION_H

