/**
 * \file GaussSeidel.h, Contains the GaussSeidel class.
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
#ifndef PARTICLE_GAUSSSEIDEL_H
#define PARTICLE_GAUSSSEIDEL_H

namespace particle {
    /**
     * \class GaussSeidel, Calculates the Gauss-Seidel relaxation.
     */
    class GaussSeidel {
        public:
            /**
             * Constructs a GaussSeidel with the given numCorrections.
             *
             * \param numCorrections int, The number of corrections.
             */
            explicit GaussSeidel (int numCorrections)
              : numCorrections_ (numCorrections) {};

            /**
             * Calculates the Gauss-Seidel relaxation.
             *
             * \tparam Particle, The type of particle.
             *
             * \param particle Particle&, The particle to correct.
             *
             * \return void.
             */
            template<class Particle>
            void operator() (Particle& particle) const {
                typename Particle::iterator endIter = particle.constraints ().end ();
                for (int i = 0; i < numCorrections_; ++i)
                    for (typename Particle::iterator curIter = particle.constraints ().begin (); curIter != endIter; ++curIter)
                        (*curIter)->operator() ();
            };

        private:
            /**
             * The number of times to calculate the correction.
             */
            int numCorrections_;
    }; //GaussSeidel
}; //particle

#endif //PARTICLE_GAUSSSEIDEL_H

