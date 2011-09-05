/**
 * \file Action.h, Contains the Action class.
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
#ifndef PARTICLE_ACTION_H
#define PARTICLE_ACTION_H

#include "particles/common.h"

namespace particle {
    /**
     * \class Action, Act on a particle.
     *
     * \tparam Particle, The type of the particle on which to act.
     */
    template<class Particle>
    class Action {
        public:
            /**
             * Act on a particle.
             *
             * \param particle Particle&, The particle on which to act.
             *
             * \return void.
             */
            virtual void operator() (Particle& particle) = 0;

            /**
             * Determines if the Action has finished.
             *
             * \return bool, True if done, false otherwise.
             */
            virtual bool isDone () const { return false; };
    }; //Action
}; //particle

#endif //PARTICLE_ACTION_H
