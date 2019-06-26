#pragma once

#include "dominios.hpp"

class IControladorDeErro {
 public:
  virtual Quadro adicionarControle(const Quadro&) = 0;
  virtual Quadro controlarErros(const Quadro&) = 0;
};

class ControladorBitParidadePar : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
 private:
  Bit bitParidadePar(const Quadro&);
};

class ControladorBitParidadeImpar : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
 private:
  Bit bitParidadeImpar(const Quadro&);
};

class ControladorCRC : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorCodigoDeHamming : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro& quadro) override;
 private:
  /** @brief  Desloca o quadro para a esquerda, tirando seu primeiro termo. 
   * @param quadro  Quadro a ser deslocado.
   * @return Quadro  Quadro com bits deslocados. (tail quadro) */
  Quadro shiftLeft(const Quadro& quadro);

  /**  @brief  Deslocar o quadro para direita
   * @param quadro  Quadro a ser deslocado a direita.
   * @return Quadro  Quadro com um 0 a mais na esquerda. ([0] ++ quadro) */
  Quadro shiftRight(const Quadro& quadro);

  /** @brief mover os bits de mensagem para as posições corretas pela
   * codificação de Hamming, deixando os índices potencias de 2 com
   * com o valor 0; 
   * @return Quadro  Quadro com os bits de mensagem movidos */
  Quadro moverBitsDados(const Quadro&);

  /** @brief Adicionar os bits de paridade nos índices potências de 2.
   * @return Quadro  Quadro com o código de hamming para o Quadro fornecido.*/
  Quadro adicionarBitsParidade(const Quadro&);

  /** @brief  Calcula o bit de paridade dado um quadro e a posição do bit de
   * paridade. 
   * @param potencia2  Posição do índice do bit de paridade. 
   * @return Bit */
  Bit bitParidade(int potencia2, const Quadro&);
};