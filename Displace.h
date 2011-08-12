/**
 * \file Displace.h, Contains the Displace class.
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
#ifndef PARTICLE_DISPLACE_H
#define PARTICLE_DISPLACE_H

#include "particles/Action.h"

namespace particle {
    /**
     * \class Displace, Displaces a particle.
     *
     * \tparam Integrator, The type of the Integrator to use to calculate the displacement.
     * \tparam Particle, the type of the particle.
     */
    template<class Integrator, class Particle>
    class Displace : public Action<Particle> {
        public:
            /**
             * Displaces a particle.
             *
             * \param integrator const Integrator&, The Integrator to use to calculate the displacement.
             */
            explicit Displace (const Integrator& integrator)
                : Action<Particle> (), integrator_ (integrator) {};

            /**
             * Displaces a particle.
             *
             * \param particle Particle&, The particle to displace.
             *
             * \return void.
             */
            virtual void operator() (Particle& particle) { integrator_ (particle); };

        private:
            /**
             * The Integrator to use to calculate the displacement.
             */
            Integrator integrator_;
    }; //Displace
}; //particle

#endif //PARTICLE_DISPLACE_H

