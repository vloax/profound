# Jogadores de Futebol, Java
Neste Trabalho Prático sua tarefa é organizar as informações dos jogadores disponíveis para exibição ao usuário. Os dados foram obtidos a partir de uma busca no site Kaggle. Você deve ler, organizar e armazenar os dados de cada jogador em memória, utilizando as estruturas de dados em aula. Em seguida executar as operações descritas nos arquivos de entrada. Muito cuidado ao realizar o parser do texto. Fique atento a descrição dos dados que serão lidos e manipulados pelo seu sistema.

Crie uma classe Jogadores. Sua classe terá os atributos Nome (String), Foto (String), Nascimento (Data), Id(int) e Times(Array de inteiros). Ela terá também os métodos imprimir e ler. O método imprimir mostra a String ’id nome nascimento foto (times)’, contendo todos os atributos da classe. O método ler deve efetuar a leitura dos atributos de um registro. A entrada padrão é composta por várias linhas e cada uma contém dados do jogador que devem ser tratados e armazenados em objetos da classe Jogador. A última linha da entrada contém FIM. A saída padrão também contém várias linhas, uma para cada registro contido na entrada padrão, conforme o exemplo abaixo: 42373 Diego Alves 24/06/1985 https://tmssl.akamaized.net/images/portrait/header/42373-1543845950.jpg (614, 330)

### Entrada  q1.in
117,Frickson Erazo,https://tmssl.akamaized.net//bilder/spielerfotos/s_163434_614_2014_01_23_1.jpg,5/05/1988,/frickson-erazo/profil/spieler/163434,163434,"[614, 210, 330, 978]"

### Saida    q1.out
42373 Diego Alves 24/06/1985 https://tmssl.akamaized.net/images/portrait/header/42373-1543845950.jpg (614, 330)