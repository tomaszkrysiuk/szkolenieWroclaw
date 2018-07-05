#include "bankruptcyobserver.h"

BankruptcyObserver::BankruptcyObserver()
{

}

unsigned BankruptcyObserver::getBankruptciesCount()
{
    return bankruptcies;
}

void BankruptcyObserver::notifyAboutBankruptcy()
{
    bankruptcies++;
}

