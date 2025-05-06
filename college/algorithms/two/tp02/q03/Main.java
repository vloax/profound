import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

public class Main {
  public static final String student = "877284";
  public static Scanner sc = new Scanner(System.in);

  /**
   * Analisa uma linha CSV, tratando campos entre aspas corretamente
   * 
   * @param line Linha CSV a ser analisada
   * @return Array com os campos extraídos
   */
  public static String[] parseLine(String line) {
    boolean hasQuote = false;
    String[] values = new String[11];
    int fieldIndex = 0;
    StringBuilder currentValue = new StringBuilder();

    for (int i = 0; i < line.length(); i++) {
      char c = line.charAt(i);

      if (c == '\"') {
        hasQuote = !hasQuote;
      } else if (c == ',' && !hasQuote) {
        values[fieldIndex++] = currentValue.toString();
        currentValue = new StringBuilder();
      } else {
        currentValue.append(c);
      }
    }

    // Adiciona o último valor
    if (fieldIndex < values.length) {
      values[fieldIndex] = currentValue.toString();
    }

    return values;
  }

  /**
   * Converte uma string de data para um objeto Date
   * 
   * @param dateStr String de data no formato "Month d, yyyy"
   * @return Objeto Date ou data padrão se a entrada for inválida
   */
  private static Date parseDate(String dateStr) {
    if (dateStr == null || dateStr.trim().isEmpty()) {
      try {
        SimpleDateFormat format = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
        return format.parse("March 1, 1900");
      } catch (ParseException e) {
        System.err.println("Erro ao analisar a data padrão: March 1, 1900");
        return null;
      }
    }

    try {
      SimpleDateFormat format = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
      return format.parse(dateStr);
    } catch (ParseException e) {
      System.err.println("Erro ao analisar a data: " + dateStr);
      return null;
    }
  }

  /**
   * Analisa e ordena uma string de valores separados por vírgula
   * 
   * @param value String a ser analisada
   * @return Array de strings ordenado
   */
  private static String[] parseStrArray(String value) {
    if (value == null || value.trim().isEmpty()) {
      return new String[0];
    }

    String[] items = value.split(",");
    for (int i = 0; i < items.length; i++) {
      items[i] = items[i].replaceFirst("^\\s+", "");
    }

    Arrays.sort(items);

    return items;
  }

  /**
   * Classe Show que representa um programa do Disney+
   */
  public static class Show implements Cloneable {
    private String show_id;
    private String type;
    private String title;
    private String director;
    private String[] cast;
    private String country;
    private Date date_added;
    private int release_year;
    private String rating;
    private String duration;
    private String[] listed_in;

    /**
     * Construtor completo
     */
    public Show(String show_id, String type, String title, String director, String[] cast, String country,
        Date date_added, int release_year, String rating, String duration, String[] listed_in) {
      this.show_id = show_id;
      this.type = type;
      this.title = title;
      this.director = director;
      this.cast = cast;
      this.country = country;
      this.date_added = date_added;
      this.release_year = release_year;
      this.rating = rating;
      this.duration = duration;
      this.listed_in = listed_in;
    }

    /**
     * Construtor vazio
     */
    public Show() {
      this.show_id = null;
      this.type = null;
      this.title = null;
      this.director = null;
      this.cast = new String[0];
      this.country = null;
      this.date_added = null;
      this.release_year = 0;
      this.rating = null;
      this.duration = null;
      this.listed_in = new String[0];
    }

    /**
     * Método clone para criar uma cópia do objeto
     * 
     * @return Uma cópia do objeto Show
     */
    @Override
    public Show clone() {
      Show clone = new Show();
      clone.show_id = this.show_id;
      clone.type = this.type;
      clone.title = this.title;
      clone.director = this.director;
      clone.cast = this.cast != null ? this.cast.clone() : new String[0];
      clone.country = this.country;
      clone.date_added = this.date_added != null ? (Date) this.date_added.clone() : null;
      clone.release_year = this.release_year;
      clone.rating = this.rating;
      clone.duration = this.duration;
      clone.listed_in = this.listed_in != null ? this.listed_in.clone() : new String[0];
      return clone;
    }

    /**
     * Método para ler os dados de um Show a partir de tokens
     * 
     * @param tokens Array com os campos do Show
     */
    public void ler(String[] tokens) {
      if (tokens == null || tokens.length < 11) {
        return;
      }

      this.show_id = tokens[0] != null && !tokens[0].isEmpty() ? tokens[0] : null;
      this.type = tokens[1] != null && !tokens[1].isEmpty() ? tokens[1] : null;
      this.title = tokens[2] != null && !tokens[2].isEmpty() ? tokens[2] : null;
      this.director = tokens[3] != null && !tokens[3].isEmpty() ? tokens[3] : null;
      this.cast = parseStrArray(tokens[4]);
      this.country = tokens[5] != null && !tokens[5].isEmpty() ? tokens[5] : null;
      this.date_added = parseDate(tokens[6]);

      try {
        this.release_year = tokens[7] != null && !tokens[7].isEmpty() ? Integer.parseInt(tokens[7]) : 0;
      } catch (NumberFormatException e) {
        this.release_year = 0;
      }

      this.rating = tokens[8] != null && !tokens[8].isEmpty() ? tokens[8] : null;
      this.duration = tokens[9] != null && !tokens[9].isEmpty() ? tokens[9] : null;
      this.listed_in = parseStrArray(tokens[10]);
    }

    /**
     * Imprime os atributos do Show no formato especificado
     */
    public void imprimir() {
      System.out.print("=> " + (show_id != null && !show_id.isEmpty() ? show_id : "NaN") + " ## ");
      System.out.print((title != null && !title.isEmpty() ? title : "NaN") + " ## ");
      System.out.print((type != null && !type.isEmpty() ? type : "NaN") + " ## ");
      System.out.print((director != null && !director.isEmpty() ? director : "NaN") + " ## ");

      System.out.print("[");
      if (cast != null && cast.length > 0) {
        for (int i = 0; i < cast.length; i++) {
          System.out.print(cast[i] != null && !cast[i].isEmpty() ? cast[i] : "NaN");
          if (i < cast.length - 1) {
            System.out.print(", ");
          }
        }
      } else {
        System.out.print("NaN");
      }
      System.out.print("] ## ");

      System.out.print((country != null && !country.isEmpty() ? country : "NaN") + " ## ");

      if (date_added != null) {
        SimpleDateFormat sdf = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
        System.out.print(sdf.format(date_added) + " ## ");
      } else {
        System.out.print("NaN ## ");
      }

      System.out.print((release_year != 0 ? release_year : "NaN") + " ## ");
      System.out.print((rating != null && !rating.isEmpty() ? rating : "NaN") + " ## ");
      System.out.print((duration != null && !duration.isEmpty() ? duration : "NaN") + " ## ");

      System.out.print("[");
      if (listed_in != null && listed_in.length > 0) {
        for (int i = 0; i < listed_in.length; i++) {
          System.out.print(listed_in[i] != null && !listed_in[i].isEmpty() ? listed_in[i] : "NaN");
          if (i < listed_in.length - 1) {
            System.out.print(", ");
          }
        }
      } else {
        System.out.print("NaN");
      }
      System.out.println("] ##");
    }

    // GETTERS AND SETTERS
    public String getShowId() {
      return show_id;
    }

    public void setShowId(String show_id) {
      this.show_id = show_id;
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
      return date_added;
    }

    public void setDateAdded(Date date_added) {
      this.date_added = date_added;
    }

    public int getReleaseYear() {
      return release_year;
    }

    public void setReleaseYear(int release_year) {
      this.release_year = release_year;
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
      return listed_in;
    }

    public void setListedIn(String[] listed_in) {
      this.listed_in = listed_in;
    }
  }

  /**
   * Cria um objeto Show a partir de tokens
   * 
   * @param tokens Array com os campos do Show
   * @return Objeto Show criado
   */
  public static Show store(String[] tokens) {
    Show show = new Show();
    show.ler(tokens);
    return show;
  }

  /**
   * Lê o arquivo CSV e retorna um array de objetos Show
   * 
   * @return Array com os objetos Show lidos do arquivo
   */
  public static Show[] readFile() {
    String path = "disneyplus.csv";
    String line = "";
    Show[] temp = new Show[10000];
    int count = 0;
    String[] currLine;

    try (BufferedReader br = new BufferedReader(new FileReader(path))) {
      // Pula a linha de cabeçalho
      line = br.readLine();

      while ((line = br.readLine()) != null) {
        currLine = parseLine(line);
        temp[count++] = store(currLine);
      }
    } catch (IOException e) {
      System.err.println("Erro ao ler o arquivo: " + e.getMessage());
      e.printStackTrace();
    }

    Show[] shows = new Show[count];
    for (int i = 0; i < count; i++) {
      shows[i] = temp[i];
    }

    return shows;
  }

  /**
   * Encontra um show pelo ID
   * 
   * @param id    ID do show a ser encontrado
   * @param shows Array de shows onde será feita a busca
   * @return Show encontrado ou null se não existir
   */
  public static Show findOne(String id, Show[] shows) {
    for (int i = 0; i < shows.length; i++) {
      if (shows[i] != null && shows[i].getShowId() != null && shows[i].getShowId().equals(id)) {
        return shows[i];
      }
    }
    return null;
  }

  public static void main(String args[]) {
    Show[] shows = readFile();
    ArrayList<Show> savedShows = new ArrayList<Show>();
    long inicio, fim;
    int comparacoes = 0;
    String id;
    String title;
    String exists;

    id = sc.nextLine();
    while (!id.equals("FIM")) {
      Show currShow = findOne(id, shows);
      if (currShow != null) {
        savedShows.add(currShow);
      }
      id = sc.nextLine();
    }

    inicio = new Date().getTime();

    title = sc.nextLine();
    while (!title.equals("FIM")) {
      exists = "NAO";
      for (int i = 0; i < savedShows.size(); i++) {
        comparacoes++;
        if (savedShows.get(i).getTitle().equals(title)) {
          exists = "SIM";
        }
      }
      System.out.println(exists);
      title = sc.nextLine();
    }

    sc.close();
    fim = new Date().getTime();

    // total do tempo em segundos
    double tempo = (double) (fim - inicio) / 1000.0;

    try (FileWriter fw = new FileWriter(student + "_sequencial.txt")) {
      fw.write(student + "\tTempo: " + tempo + ".s" + "\tComparações: " + comparacoes);
    } catch (IOException e) {
      System.err.println("Erro ao gravar o log: " + e.getMessage());
    }
  }
}