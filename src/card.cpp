
#include card.hpp

class card
{
    public:
        card(uint8_t deckid, uint8_t suit, uint8_t card)
        {
            card_val.deckid = deckid;
            card_val.suit = suit;
            card_val.card = card;
        }
        ~card()
        {
        }

        uint8_t to_int()
        {
            uint8_t retval = 0;
            retval
            return card_val.
        }

