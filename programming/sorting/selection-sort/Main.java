import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;

class Main {
  private static void selectionSort(int[] arr) {
    String filePath = "matricula.txt";
    int n = arr.length; // pegar o tamanho do array
    int comp = 0;
    int swap = 0;
    double fim, inicio;

    inicio = new Date().getTime(); // pegar o tempo atual em milissegundos
    for (int i = 0; i < n - 1; i++) { // loop para percorrer o array até n-1

      int minIndex = i; // assume o primeiro elemento como o menor

      for (int j = i + 1; j < n; j++) {
        comp++; // incrementar o contador de comparações
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      }

      swap++; // incrementar o contador de trocas
      int temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
    }
    fim = new Date().getTime(); // pegar o tempo atual em milissegundos

    String content = "Tempo de execução: " + (fim - inicio) + " ms\n" +
        "Número de comparações: " + comp + "\n" +
        "Número de trocas: " + swap + "\n" +
        "Array ordenado: \n";

    try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
      writer.write(content);
      System.out.println("Successfully wrote to the file.");
    } catch (IOException e) {
      System.err.println("An error occurred while writing to the file: " + e.getMessage());
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    int arr[] = new int[10];

    // Preencher o array com números aleatórios
    for (int i = 0; i < arr.length; i++) {
      arr[i] = (int) (Math.random() * 10); // números aleatórios entre 0 e 999
    }
    System.out.println();

    selectionSort(arr);
  }
}