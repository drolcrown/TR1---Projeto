#pragma once

#include "dominios.hpp"

using namespace std;


class IControladorDeErro {
 public:
    virtual Quadro adicionarControle(const Quadro& ) = 0;
    virtual Quadro controlarErros(const Quadro& ) = 0; 

};

class ControladorCRC : public IControladorDeErro{

public:
    Quadro adicionarControle(const Quadro&) override;
    Quadro controlarErros(const Quadro&) override;
};