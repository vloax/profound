/*
  Crie uma classe shows seguindo todas as regras apresentadas no slide unidade00l_conceitosBasicos_introducaoOO.pdf. Sua classe terá os atributos privado 
  show_id: string, type: string, title: string, director: string, cast: string[], country: string, date_added: date, release_year: int, rating: string, duration: string, listed_in: string[]. 
  Sua classe também terá pelo menos dois construtores, e os métodos gets, sets, clone, imprimir e ler.
  O método imprimir mostra os atributos do registro (ver cada linha da saída padrão) e o ler lê os atributos de um registro. Atenção para o arquivo de entrada, pois em alguns registros faltam valores e esse deve ser substituído pelo valor NaN. A entrada padrão é composta por várias linhas e cada uma contém um número inteiro indicando o show_id do shows a ser lido.
  A última linha da entrada contém a palavra FIM. A saída padrão também contém várias linhas, uma para cada registro contido em uma linha da entrada padrão, no seguinte formato: [=> id ## type ## title ## director ## [cast] ## country ## date_added ## release_year ## rating ## duration ## [listed_in].
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

public class Main {
  public static Scanner sc = new Scanner(System.in);

  public static String[] parser(String line) {
    boolean hasQuotes = false;
    String[] valores = new String[11];
    int fIdx = 0; // id = 0, type = 1;
    StringBuilder valorAtual = new StringBuilder();

    for (int i = 0; i < line.length(); i++) {
      char c = line.charAt(i);

      if (c == '"') {
        hasQuotes = !hasQuotes;
      } else if (c == ',' && !hasQuotes) {
        valores[fIdx] = valorAtual.toString();
        valorAtual = new StringBuilder();
        fIdx++;
      } else {
        valorAtual.append(c);
      }
    }

    return valores;
  }

  public static String[] formatarStringEmArray(String str) {
    if (str == null || str.isEmpty()) {
      return new String[] { "NaN" }; // Retorna um array com "NaN" se a string estiver vazia ou nula
    }

    String[] array = str.split(","); // Divide a string em partes usando a vírgula como delimitador

    for (int i = 0; i < array.length; i++) {
      array[i] = array[i].trim();
    }

    Arrays.sort(array);

    return array;
  }

  private static Date parseDate(String dateStr) {
    if (dateStr == null || dateStr.isEmpty()) {
      return new Date(0); // Retorna uma data padrão (1 de março de 1900)
    }

    try {
      SimpleDateFormat format = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
      return format.parse(dateStr);
    } catch (ParseException e) {
      System.err.println("Erro ao analisar a data: " + dateStr);
      return null;
    }
  }

  public static class Show {
    private String showId;
    private String type;
    private String title;
    private String director;
    private String[] cast;
    private String country;
    private Date dateAdded;
    private int releaseYear;
    private String rating;
    private String duration;
    private String[] listedIn;

    // CONSTRUCTORS
    public Show(String showId, String type, String title, String director, String[] cast, String country,
        Date dateAdded, int releaseYear, String rating, String duration, String[] listedIn) {
      this.showId = showId;
      this.type = type;
      this.title = title;
      this.director = director;
      this.cast = cast;
      this.country = country;
      this.dateAdded = dateAdded;
      this.releaseYear = releaseYear;
      this.rating = rating;
      this.duration = duration;
      this.listedIn = listedIn;
    }

    public Show() {
      this.showId = "NaN";
      this.type = "NaN";
      this.title = "NaN";
      this.director = "NaN";
      this.cast = new String[] { "NaN" };
      this.country = "NaN";
      this.dateAdded = new Date(0);
      this.releaseYear = 0;
      this.rating = "NaN";
      this.duration = "NaN";
      this.listedIn = new String[] { "NaN" };
    }

    // GETTERS AND SETTERS
    public String getShowId() {
      return showId;
    }

    public void setShowId(String showId) {
      this.showId = showId;
    }

    public String getType() {
      return type;
    }

    public void setType(String type) {
      this.type = type;
    }

    public String getTitle() {
      return title;
    }

    public void setTitle(String title) {
      this.title = title;
    }

    public String getDirector() {
      return director;
    }

    public void setDirector(String director) {
      this.director = director;
    }

    public String[] getCast() {
      return cast;
    }

    public void setCast(String[] cast) {
      this.cast = cast;
    }

    public String getCountry() {
      return country;
    }

    public void setCountry(String country) {
      this.country = country;
    }

    public Date getDateAdded() {
      return dateAdded;
    }

    public void setDateAdded(Date dateAdded) {
      this.dateAdded = dateAdded;
    }

    public int getReleaseYear() {
      return releaseYear;
    }

    public void setReleaseYear(int releaseYear) {
      this.releaseYear = releaseYear;
    }

    public String getRating() {
      return rating;
    }

    public void setRating(String rating) {
      this.rating = rating;
    }

    public String getDuration() {
      return duration;
    }

    public void setDuration(String duration) {
      this.duration = duration;
    }

    public String[] getListedIn() {
      return listedIn;
    }

    public void setListedIn(String[] listedIn) {
      this.listedIn = listedIn;
    }

    // CLONE METHOD
    public Show clone() {
      return new Show(this.showId, this.type, this.title, this.director, this.cast, this.country,
          this.dateAdded, this.releaseYear, this.rating, this.duration, this.listedIn);
    }

    public void ler(String[] campos) {
      this.showId = campos[0];
      this.type = campos[1];
      this.title = campos[2];
      if (campos[3] != null && !campos[3].isEmpty()) {
        this.director = campos[3];
      } else {
        this.director = "NaN";
      }
      this.cast = formatarStringEmArray(campos[4]);
      if (campos[5] != null && !campos[5].isEmpty()) {
        this.country = campos[5];
      } else {
        this.country = "NaN";
      }
      this.dateAdded = parseDate(campos[6]);
      if (campos[7] != null && !campos[7].isEmpty()) {
        this.releaseYear = Integer.parseInt(campos[7]);
      } else {
        this.releaseYear = 0;
      }
      this.rating = campos[8];
      this.duration = campos[9];
      this.listedIn = formatarStringEmArray(campos[10]);
    }

    // IMPRIMIR METHOD
    public void imprimir() {
      System.out.println("=> " + this.showId + " ## " + this.title + " ## " + this.type + " ## " + this.director
          + " ## [" + String.join(", ", this.cast) + "] ## " + this.country + " ## "
          + new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH).format(this.dateAdded) + " ## " + this.releaseYear
          + " ## "
          + this.rating + " ## " + this.duration + " ## [" + String.join(", ", this.listedIn) + "] ##");
    }
  }

  public static Show guardar(String[] campos) {
    Show show = new Show();
    show.ler(campos);
    return show;
  }

  public static Show[] lerArquivo() {
    String caminhoArquivo = "/tmp/disneyplus.csv";
    String linha = null;
    Show[] shows = new Show[1368]; // Array para armazenar os shows

    try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
      int i = 0;

      br.readLine();

      while ((linha = br.readLine()) != null) {
        String[] campos = parser(linha);
        shows[i] = guardar(campos);
        i++;
      }
    } catch (IOException e) {
      System.err.println("Erro ao ler o arquivo: " + e.getMessage());
    }

    return shows;
  }

  public static Show acharShowPeloId(Show[] shows, String id) {
    Show show = null;
    int idx = 0;

    while (idx < shows.length && show == null) {
      if (shows[idx].getShowId().equals(id)) {
        show = shows[idx];
      }
      idx++;
    }

    return show;
  }

  public static void main(String[] args) {
    Show[] shows = lerArquivo();
    ArrayList<Show> listaShows = new ArrayList<Show>();

    String linhaEntrada = "";

    while (!linhaEntrada.equals("FIM")) {
      if (linhaEntrada.equals("FIM")) {
        break;
      }

      linhaEntrada = sc.next();
      Show show = acharShowPeloId(shows, linhaEntrada);
      listaShows.add(show);
    }

    listaShows.sort((a, b) -> {
      if (a == null)
        return -1;
      if (b == null)
        return 1;
      return a.getTitle().compareTo(b.getTitle());
    });

    for (Show show : listaShows) {
      if (show != null) {
        show.imprimir();
      }
    }

    sc.close();
  }

}