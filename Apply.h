/**
 * \file Apply.h, Constains the Apply class.
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
#ifndef PARTICLE_APPLY_H
#define PARTICLE_APPLY_H

#include "particles/common.h"
#include "particles/Action.h"

namespace particle {
    /**
     * \class Apply, Applies a force to a particle.
     *
     * \tparam Force, The type of the force.
     * \tparam Particle, The type of the particle.
     */
    template<class Force, class Particle>
    class Apply : public Action<Particle> {
        public:
            /**
             * Constructs an Apply with a Force.
             *
             * \param const Force& force, The force to apply.
             */
            explicit Apply (const Force& force)
              : Action<Particle> (), force_ (force) {};

            /**
             * Applies a force to a paricle.
             *
             * \param Particle& particle, The particle to which to apply the force.
             *
             * \return void.
             */
            virtual void operator() (Particle& particle) {
                particle.force () += force_ (particle);
            };

            /**
             * Determines if the force is done being applied to the particle.
             *
             * \return bool, True if the force is done, false otherwise.
             */
            bool isDone () const { return force_.isDone (); };

        private:
            /**
             * The force to apply to the particle.
             */
            Force force_;
    }; //Apply
}; //particle

#endif //PARTICLE_APPLY_H

