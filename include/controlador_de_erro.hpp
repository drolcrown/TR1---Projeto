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

  /** @brief  Retorna um quadro sem a codificação de  no tamanho original.
   * @param quadro  Quadro com codificação de hamming.
   * @return Quadro  Quadro sem a codificação de hamming. */
  Quadro removerBitsParidade(const Quadro& quadro);

  /** @brief Compara os bits de paridades das codificações de hamming.
   * @return std::vector<int>  Vetor com os índices dos bits de paridade que
   * não foram iguais. 
   * @pre  a.size() == b.size() */
  std::vector<int> indicesDosBitsParidadeDiferentes(const Quadro& a, const Quadro& b);

  /** @brief  A partir de um quadro sem codificação de hamming e de um vetor
   *   que indica quais bits de paridade estão incorretos, corrige o quadro.
   * @param quadro  Quadro sem a codificação de hamming.
   * @param paridades_divergentes  Vetor que mostra os bits de paridade que
   *  divergiram na codificação de hamming teorica e recebida do quadro.
   * @return Quadro  Quadro com bits corrigidos. */
  Quadro corrigirQuadro(const Quadro &quadro, const std::vector<int>& paridades_divergentes);
};