/**
 * \file ViscuousDrag.h, Contains the ViscuousDrag class.
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
#ifndef PARTICLE_VISCUOUSDRAG_H
#define PARTICLE_VISCUOUSDRAG_H

#include "particles/common.h"

namespace particle {
    /**
     * \class ViscuousDrag, Calculates the viscuous drag on a particle.
     */
    class ViscuousDrag {
        public:
            /**
             * Constructs a ViscuousDrag with the given drag coefficient.
             *
             * \param drag float, The drag coefficient.
             */
            explicit ViscuousDrag (float drag)
              : drag_ (drag) {};

            /**
             * Calculates the viscuous drag on a particle.
             *
             * \tparam Particle, The type of the particle.
             *
             * \param particle Particle&, the particle for which to calculate the viscuous drag.
             *
             * \return Vector, the viscuous drag on the particle.
             */
            template<class Particle>
            Vector operator() (Particle& particle) {
                if (!particle.pinned ())
                    return particle.velocity () * -drag_;
                return make_Vector (0.0f, 0.0f, 0.0f);
            };

            /**
             * Determines if the ViscuousDrag is done.
             *
             * \return bool, Ture if done, flase otherwise.
             */
            bool isDone () const { return false; };

        private:
            /**
             * The drag coefficient.
             */
            float drag_;
    }; //ViscuousDrag
}; //particle

#endif //PARTICLE_VISCUOUSDRAG_H

