/* Notes:
 *  - innterfaced from pile classes
 *
 *  Rank of suits: (Bridge Rules: high to low) spades, hearts, diamonds, clubs
 *
 *  Methods:
 *      - public constructor allows for more than one deck in the game, in this
 *      case the 2 bit deckid that is part of the card
 *      - public "shuffle"
 *      - public "collect all"
 *      - private struct {8b card, 8b pile id, 8b index next, 8b index previous}
 */

#include <card.hpp>
struct deck_struct
{
    card card;
    uint8_t pile_id;
    uint8_t next;
    uint8_t prev;
};

class deck
{
    public:
        deck(uint2_t);
        ~deck();
        uint8_t shuffle();
        uint8_t collect_all();

        /*
         * Actual implementation of the piles
         * Piles meerly make a call to the deck to perform the action
         */
        uint8_t push();
        uint8_t pop();
        uint8_t enqueue();
        uint8_t dequeue();
        uint8_t topdeck();
        uint8_t untopdeck();
        uint8_t set_visibility();
        uint8_t move();

    private:
        deck_struct deck[]
}
