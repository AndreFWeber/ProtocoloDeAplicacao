#ifndef ASN1UTIME
#define ASN1UTIME

#include <asn1++/asn1-string.h>
#include <UTCTime.h>

using namespace std;

// classe para auxiliar o acesso, conversão e modificação de strings ASN1
class ASN1Utime : public ASN1String {
 public:
  // Constructor: parâmetro "astr" é um ponteiro para uma string ASN1
  //ASN1Utime(OCTET_STRING_t & astr);
  ASN1Utime(OCTET_STRING_t & astr) : ASN1String(astr) {}
  ASN1Utime(time_t t);
  ASN1Utime(ASN1Utime & other);
  ASN1Utime() : ASN1String("000101000000-0000") {}
  //ASN1Utime();
  virtual ~ASN1Utime() {}

  // Operadores de atribuição: uma forma conveniente de modificar a string
  virtual ASN1Utime & operator=(const ASN1Utime & other);
  virtual ASN1Utime & operator=(time_t t);

  // Operadores de concatenação: uma forma conveniente de modificar a string
  virtual ASN1Utime & operator+=(time_t t);

  // retorna o valor do tempo
  time_t get_time() const;
};

#endif
