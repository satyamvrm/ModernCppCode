#ifndef DEBITCARD_H
#define DEBITCARD_H
#include <ostream>

class DebitCard
{
private:
    /* data */
    long int _cardNumber;
    unsigned int _cvv;

public:
    DebitCard(/* args */) = default;
    DebitCard(const DebitCard &) = delete;
    DebitCard(DebitCard &&) = delete;
    DebitCard &operator=(const DebitCard &) = delete;
    DebitCard &operator=(DebitCard &&) = delete;
    ~DebitCard() = default;

    DebitCard(long int cardNo, unsigned int cvv) : _cardNumber{cardNo}, _cvv{cvv} {}

    long int cardNumber() const { return _cardNumber; }
    void setCardNumber(long int cardNumber) { _cardNumber = cardNumber; }

    unsigned int cvv() const { return _cvv; }
    void setCvv(unsigned int cvv) { _cvv = cvv; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);

    
};

inline std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_cardNumber: " << rhs._cardNumber
       << " _cvv: " << rhs._cvv;
    return os;
}

#endif // DEBITCARD_H
