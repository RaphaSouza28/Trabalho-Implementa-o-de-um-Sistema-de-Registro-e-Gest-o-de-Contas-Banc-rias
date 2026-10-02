# Banco Enlace – Sistema de Registro e Gestão de Contas Bancárias

   Trabalho da disciplina **INF101 – Programação de Computadores I** (UNIVIÇOSA)

   **Professores:** Anderson R. Lamas e Vanderlea Queiroz

   **Aluno:** Raphael de Souza Azevedo - 26338

## Etapa 1 – Variáveis e estruturas de controle

| Arquivo | Descrição |
|---|---|
| `main.cpp` | Sistema principal: cadastro e gestão de **uma** conta usando apenas variáveis individuais |
| `banco_5_contas.cpp` | Desafio 3.5: versão que cadastra **até 5 contas** |

### Funcionalidades (menu com `switch` dentro de `do-while`)

1. Cadastrar conta
2. Consultar conta
3. Verificar saldo
4. Alterar tipo da conta
5. Ativar/Desativar conta
6. Sair

### Validações

- Número da conta deve ser maior que zero
- Saldo inicial não pode ser negativo
- Tipo da conta deve ser 1 (Corrente) ou 2 (Poupança)
- Verificar saldo e alterar tipo só funcionam com a conta **ativa** (`contaAtiva`)
- Extras: CPF com 11 dígitos, nome não vazio, proteção contra letras digitadas em campos numéricos

### Variáveis extras (desafio)

- `telefone` (string): telefone do titular
- `contaCadastrada` (bool): impede consultar/alterar antes de existir uma conta

## Como compilar e executar

```bash
g++ main.cpp -o banco
./banco            # Linux/Mac
banco.exe          # Windows
```

Para a versão de 5 contas:

```bash
g++ banco_5_contas.cpp -o banco5
./banco5
```

## Desafio: e se quiséssemos cadastrar até 5 contas?

Usando só variáveis individuais, a única saída é criar **5 conjuntos de variáveis**
(`numeroConta1` … `numeroConta5`, `saldo1` … `saldo5` etc.). Em `banco_5_contas.cpp`:

1. a conta é localizada pelo número com uma cadeia de `if/else`;
2. os dados dela são copiados para variáveis "de trabalho";
3. a operação é feita nessas variáveis;
4. os dados são copiados de volta para a conta original.

**Limitação:** o código fica longo e repetitivo, e cada conta a mais exige novas
variáveis e mais linhas em todos os `if` e `switch`. Para 100 contas seria inviável.
A solução adequada é usar **arrays (vetores)** e **funções**, conteúdo da Etapa 2.
