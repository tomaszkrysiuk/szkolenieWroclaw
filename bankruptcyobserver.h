#pragma once


class BankruptcyObserver
{
public:
    BankruptcyObserver();
    void notifyAboutBankruptcy();

    unsigned getBankruptciesCount();
private:
    unsigned bankruptcies = 0;
};

