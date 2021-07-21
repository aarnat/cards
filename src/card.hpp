/* Notes:
 *  - 8bit: 2bit deckid; 2bit suit; 4bit card#
 *  - may need to be bigger in the future for more decks?
 *  Rank of suits: (Bridge Rules: high to low) spades(11), hearts(10), diamonds(01), clubs(00)
 *
 *  Variables:
 *      - private
 *
 *  Methods:
 *      - public "to string" (ie. Five of Diamonds)
 *      - public "to shorthand" (ie. 5d)
 *      - public "value" (no deck id nor suit: ie. 5)
 *      - public "to int" (no deck id: ie 21 [01 0101])
 *      - private? "get deck id"
 */

#include <string.h>
#include <cstdint>

#define DECK_MASK   192     //1100 0000
#define SUIT_MASK    48     //0011 0000
#define VALUE_MASK   15     //0000 1111
#define FACE_MASK    63     //0011 1111

class card
{
    public:
        card(uint8_t deckid, uint8_t suit, uint8_t card);
        ~card();
        uint8_t to_int();

        uint8_t to_value();

    private:
        struct card_val{
            uint8_t deckid   : 2;
            uint8_t suit     : 2;
            uint8_t card     : 4;
        }
}
