/* Notes:
 *  - each pile can have a configurable size
 *
 *  Variables:
 *      - private struct
 *          - card
 *          - current size
 *          - first card index
 *          - last card index
 *          - Visibility type discard/all visible(11), hand(10), topdeck(01), draw pile (00)
 *      -private permissions?
 *      -private
 *
 *  Methods:
 *      - public "push()" (put on top)
 *      - public "pop()" (get from top)
 *      - public "enqueue()" (put on bottom)
 *      - public "dequeue()" (get from bottom)
 *      - public "topdeck()" (Reveal the top card)
 *      - public "untopdeck()" (Reveal the top card)
 *      - public "set_visibility()" (set visibility type)
 *      - private "move()" (notifies deck to change pile id)
 *      - private "get_deck_id()" ?
 *      - private "head"
 *      - private "tail"
 */

#include <vector>

#include <card.h>

class pile
{
    public:
        pile();
        ~pile();

        uint8_t push();
        uint8_t pop();
        uint8_t enqueue();
        uint8_t dequeue();
        uint8_t topdeck();
        uint8_t untopdeck();
        uint8_t set_visibility();
        uint8_t move();

    private:
        uint8_t get_deck_id();
        deck deck*; //Pointer to the deck object
        //std::vector<uint8_t> cards;
}
