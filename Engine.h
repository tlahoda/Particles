/**
 * \file Engine.h, Contains the Engine class.
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
#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#include <algorithm>

#include <boost/mpl/for_each.hpp>

namespace particle {
    /**
     * \class Engine, Provides a mechanism for manipulating groups of particles.
     */
    class Engine {
        public:
            /**
             * \class Reaction, Applies a reaction to a reactant.
             *
             * \tparam Reactant, The type of the Reactant.
             */
            template<class Reactant>
            class Reaction {
                public:
                    /**
                     * Constructs a reaction for a reactant.
                     *
                     * \param reactant Reactant&, The reactant to react.
                     */
                    explicit Reaction (Reactant& reactant)
                      : reactant_ (reactant) {};

                    /**
                     * Applies a reactor to a reactant.
                     *
                     * \tparam Reactor, The type of the Reactor.
                     *
                     * \param reactor Reactor&, The reactor to apply.
                     *
                     * \return void.
                     */
                    template<class Reactor>
                    void operator() (Reactor& reactor) const {
                        (*reactor) (reactant_);
                    };

                private:
                    /**
                     * The reactant to manipulate.
                     */
                    Reactant& reactant_;
            }; //Reaction

            /**
             * \class MultiReaction, Applies multiple reactions to a reactant.
             *
             * \tparam Iterator, The type of the Iterator.
             */
            template<class Iterator>
            class MultiReaction {
                public:
                      /**
                       * Constructs a MultiReaction from a group of ractions.
                       *
                       * \param begin const Iterator&, The start of the reactions.
                       * \param end const Iterator&, The end of the reactions.
                       */
                      MultiReaction (const Iterator& begin, const Iterator& end)
                        : begin_ (begin), end_ (end) {};

                      /**
                       * Applies a group of reactions to the reactant.
                       *
                       * \param Reactant, The type of the Reactant.
                       *
                       * \param reactant Reactant&, The reactant to which to apply the reactions.
                       *
                       * \return void.
                       */
                      template<class Reactant>
                      void operator() (Reactant& reactant) const {
                          std::for_each (begin_, end_, Reaction<Reactant> (reactant));
                      };

                  private:
                      /**
                     * The start of the reactions.
                     */
                    const Iterator& begin_;

                    /**
                     * The end of the reactions.
                     */
                    const Iterator& end_;
            }; //MultiReaction

        public:
            /**
             * Constructs an engine.
             */
            Engine () {};

            /**
             * Applies a reactor to a group of reactants.
             *
             * \tparam GroupIterator, The type of the GroupIterator.
             * \tparam Reactor, The type of the Reactor.
             *
             * \param groupBegin const GroupIterator&, The start of the reactants.
             * \param groupEnd const GroupIterator&, The end of the reactants.
             * \param reactor const Reactor&, The reactor to apply.
             *
             * \return void.
             */
            template<class GroupIterator, class Reactor>
            inline void operator() (const GroupIterator& groupBegin, const GroupIterator& groupEnd, const Reactor& reactor) const {
                std::for_each (groupBegin, groupEnd, reactor);
            };

            /**
             * Applies a group of reactions to a group of reactants.
             *
             * \tparam GroupIterator, The type of the GroupIterator.
             * \tparam ActionsIterator, The type of the ActionsIterator.
             *
             * \param groupBegin const GroupIterator&, The start of the reactants.
             * \param groupEnd const GroupIterator&, The end of the reactants.
             * \param actionsBegin const ActionsIterator&, The start of the reactions.
             * \param actionsEnd const ActionsIterator&, The end of the reactions.
             *
             * \return void.
             */
            template<class GroupIterator, class ActionsIterator>
            inline void operator() (const GroupIterator& groupBegin, const GroupIterator& groupEnd, const ActionsIterator& actionsBegin, const ActionsIterator& actionsEnd) const {
                std::for_each (groupBegin, groupEnd, MultiReaction<ActionsIterator> (actionsBegin, actionsEnd));
            };

            /**
             * Applies a group of reactions to a reactant.
             *
             * \tparam Reactant, The type of the Reactant.
             * \tparam ActionsIterator, The type of the ActionsIterator.
             *
             * \param reactant Reactant&, The reactant.
             * \param actionsBegin const ActionsIterator&, The start of the reactions.
             * \param actionsEnd const ActionsIterator&, The end of the reactions.
             *
             * \return void.
             */
            template<class Reactant, class ActionsIterator>
            inline void operator() (Reactant& reactant, const ActionsIterator& actionsBegin, const ActionsIterator& actionsEnd) {
                MultiReaction<ActionsIterator> reactions (actionsBegin, actionsEnd);
                reactions (reactant);
            };
    }; //Engine
}; //particle

#endif //PARTICLE_ENGINE_H

