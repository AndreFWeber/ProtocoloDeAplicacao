#ifndef ASN1_PARSER_PTCMENSAGEM_H
#define ASN1_PARSER_PTCMENSAGEM_H

#include <asn1++/asn1++.h>

#include<Inicio.h>
#include<Erro.h>
#include<Posicao.h>
#include<Fim.h>

class TInicio : public ASN1DataType<Inicio_t> {
 public:
 private:
  ASN1String * m_nome;
 public:
  TInicio() : ASN1DataType<Inicio_t>(&asn_DEF_Inicio) {
    init();
  }
  TInicio(Inicio_t * ptr) : ASN1DataType<Inicio_t>(&asn_DEF_Inicio, ptr) {
    destroy = false;
    init();
  }
  TInicio(const TInicio & o) : ASN1DataType<Inicio_t>(&asn_DEF_Inicio, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
    m_nome = new ASN1String(pkt->nome);
  }
  virtual ~TInicio() {
    delete m_nome;
  }
  TInicio & operator=(const TInicio & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    delete m_nome;
    init();
    destroy = false;
    return *this;
}
  bool get_marca() { return pkt->marca;}
  void set_marca(bool arg) { pkt->marca = arg;}
  string get_nome() { return m_nome->str();}
  void set_nome(const string & arg) { *m_nome = arg;}
  class DerSerializer : public DERSerializer<Inicio_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Inicio_t>(&asn_DEF_Inicio, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TInicio & pkt) {DERSerializer<Inicio_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Inicio_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Inicio_t>(&asn_DEF_Inicio, inp) {}
    ~DerDeserializer() {}
    TInicio * deserialize() {
      ASN1DataType<Inicio> * p = DERDeserializer<Inicio_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInicio * scan() {
      ASN1DataType<Inicio> * p = DERDeserializer<Inicio_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInicio * get_obj(ASN1DataType<Inicio_t> * p) {
      TInicio * obj = new TInicio(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Inicio_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Inicio_t>(&asn_DEF_Inicio, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TInicio & pkt) {XERSerializer<Inicio_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Inicio_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Inicio_t>(&asn_DEF_Inicio, inp) {}
    ~XerDeserializer() {}
    TInicio * deserialize() {
      ASN1DataType<Inicio> * p = XERDeserializer<Inicio_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TInicio * scan() {
      ASN1DataType<Inicio> * p = XERDeserializer<Inicio_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TInicio * get_obj(ASN1DataType<Inicio_t> * p) {
      TInicio * obj = new TInicio(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TErro : public ASN1DataType<Erro_t> {
 public:
 private:
 public:
  TErro() : ASN1DataType<Erro_t>(&asn_DEF_Erro) {
    init();
  }
  TErro(Erro_t * ptr) : ASN1DataType<Erro_t>(&asn_DEF_Erro, ptr) {
    destroy = false;
    init();
  }
  TErro(const TErro & o) : ASN1DataType<Erro_t>(&asn_DEF_Erro, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TErro() {
  }
  TErro & operator=(const TErro & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  long get_erro() { return pkt->erro;}
  void set_erro(long arg) { pkt->erro = arg;}
  class DerSerializer : public DERSerializer<Erro_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Erro_t>(&asn_DEF_Erro, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TErro & pkt) {DERSerializer<Erro_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Erro_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Erro_t>(&asn_DEF_Erro, inp) {}
    ~DerDeserializer() {}
    TErro * deserialize() {
      ASN1DataType<Erro> * p = DERDeserializer<Erro_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TErro * scan() {
      ASN1DataType<Erro> * p = DERDeserializer<Erro_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TErro * get_obj(ASN1DataType<Erro_t> * p) {
      TErro * obj = new TErro(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Erro_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Erro_t>(&asn_DEF_Erro, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TErro & pkt) {XERSerializer<Erro_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Erro_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Erro_t>(&asn_DEF_Erro, inp) {}
    ~XerDeserializer() {}
    TErro * deserialize() {
      ASN1DataType<Erro> * p = XERDeserializer<Erro_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TErro * scan() {
      ASN1DataType<Erro> * p = XERDeserializer<Erro_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TErro * get_obj(ASN1DataType<Erro_t> * p) {
      TErro * obj = new TErro(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TPosicao : public ASN1DataType<Posicao_t> {
 public:
 private:
 public:
  TPosicao() : ASN1DataType<Posicao_t>(&asn_DEF_Posicao) {
    init();
  }
  TPosicao(Posicao_t * ptr) : ASN1DataType<Posicao_t>(&asn_DEF_Posicao, ptr) {
    destroy = false;
    init();
  }
  TPosicao(const TPosicao & o) : ASN1DataType<Posicao_t>(&asn_DEF_Posicao, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TPosicao() {
  }
  TPosicao & operator=(const TPosicao & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  long get_posicao() { return pkt->posicao;}
  void set_posicao(long arg) { pkt->posicao = arg;}
  class DerSerializer : public DERSerializer<Posicao_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Posicao_t>(&asn_DEF_Posicao, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TPosicao & pkt) {DERSerializer<Posicao_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Posicao_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Posicao_t>(&asn_DEF_Posicao, inp) {}
    ~DerDeserializer() {}
    TPosicao * deserialize() {
      ASN1DataType<Posicao> * p = DERDeserializer<Posicao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPosicao * scan() {
      ASN1DataType<Posicao> * p = DERDeserializer<Posicao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPosicao * get_obj(ASN1DataType<Posicao_t> * p) {
      TPosicao * obj = new TPosicao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Posicao_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Posicao_t>(&asn_DEF_Posicao, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TPosicao & pkt) {XERSerializer<Posicao_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Posicao_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Posicao_t>(&asn_DEF_Posicao, inp) {}
    ~XerDeserializer() {}
    TPosicao * deserialize() {
      ASN1DataType<Posicao> * p = XERDeserializer<Posicao_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TPosicao * scan() {
      ASN1DataType<Posicao> * p = XERDeserializer<Posicao_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TPosicao * get_obj(ASN1DataType<Posicao_t> * p) {
      TPosicao * obj = new TPosicao(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

class TFim : public ASN1DataType<Fim_t> {
 public:
 private:
 public:
  TFim() : ASN1DataType<Fim_t>(&asn_DEF_Fim) {
    init();
  }
  TFim(Fim_t * ptr) : ASN1DataType<Fim_t>(&asn_DEF_Fim, ptr) {
    destroy = false;
    init();
  }
  TFim(const TFim & o) : ASN1DataType<Fim_t>(&asn_DEF_Fim, o.pkt) {
    init();
    destroy = false;
  }
  void init() {
  }
  virtual ~TFim() {
  }
  TFim & operator=(const TFim & o) {
    if (destroy) delete pkt;
    pkt = o.pkt;
    DESC = o.DESC;
    init();
    destroy = false;
    return *this;
}
  long get_condicao() { return pkt->condicao;}
  void set_condicao(long arg) { pkt->condicao = arg;}
  class DerSerializer : public DERSerializer<Fim_t> {
  public:
    DerSerializer(ostream & out) : DERSerializer<Fim_t>(&asn_DEF_Fim, out) {}
    ~DerSerializer() {}
    ssize_t serialize(TFim & pkt) {DERSerializer<Fim_t>::serialize(pkt);}
  };
  class DerDeserializer : public DERDeserializer<Fim_t> {
  public:
    DerDeserializer(istream & inp) : DERDeserializer<Fim_t>(&asn_DEF_Fim, inp) {}
    ~DerDeserializer() {}
    TFim * deserialize() {
      ASN1DataType<Fim> * p = DERDeserializer<Fim_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TFim * scan() {
      ASN1DataType<Fim> * p = DERDeserializer<Fim_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TFim * get_obj(ASN1DataType<Fim_t> * p) {
      TFim * obj = new TFim(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
  class XerSerializer : public XERSerializer<Fim_t> {
  public:
    XerSerializer(ostream & out) : XERSerializer<Fim_t>(&asn_DEF_Fim, out) {}
    ~XerSerializer() {}
    ssize_t serialize(TFim & pkt) {XERSerializer<Fim_t>::serialize(pkt);}
  };
  class XerDeserializer : public XERDeserializer<Fim_t> {
  public:
    XerDeserializer(istream & inp) : XERDeserializer<Fim_t>(&asn_DEF_Fim, inp) {}
    ~XerDeserializer() {}
    TFim * deserialize() {
      ASN1DataType<Fim> * p = XERDeserializer<Fim_t>::deserialize();
      if (not p) return NULL;
      return get_obj(p);
    }
    TFim * scan() {
      ASN1DataType<Fim> * p = XERDeserializer<Fim_t>::scan();
      if (not p) return NULL;
      return get_obj(p);
    }
 private:
  TFim * get_obj(ASN1DataType<Fim_t> * p) {
      TFim * obj = new TFim(p->_get_data());
      p->set_destroy(false);
      obj->set_destroy(true);
      delete p;
      return obj;
    }
  };
};

#endif
