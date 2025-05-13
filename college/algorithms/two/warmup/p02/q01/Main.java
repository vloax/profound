import java.util.Scanner;

public class Main {
  public static Scanner sc = new Scanner(System.in);

  public static class Athlete {
    String name;
    int score;

    public Athlete(String name, int score) {
      this.name = name;
      this.score = score;
    }

    public String getName() {
      return name;
    }

    public int getScore() {
      return score;
    }

    public void setName(String name) {
      this.name = name;
    }

    public void setScore(int score) {
      this.score = score;
    }

    public void print() {
      System.out.println(name + " " + score);
    }
  }

  public static void sortAthletes(Athlete[] athletes) {
    for (int i = 0; i < athletes.length - 1; i++) {
      for (int j = 0; j < athletes.length - i - 1; j++) {
        if (athletes[j].getScore() < athletes[j + 1].getScore()) {
          Athlete temp = athletes[j];
          athletes[j] = athletes[j + 1];
          athletes[j + 1] = temp;
        } else if (athletes[j].getScore() == athletes[j + 1].getScore()) {
          if (athletes[j].getName().compareToIgnoreCase(athletes[j + 1].getName()) > 0) {
            Athlete temp = athletes[j];
            athletes[j] = athletes[j + 1];
            athletes[j + 1] = temp;
          }
        }
      }
    }
  }

  public static void main(String[] args) {
    int n = sc.nextInt();
    Athlete[] athletes = new Athlete[n];
    for (int i = 0; i < n; i++) {
      String name = sc.next();
      int score = sc.nextInt();
      athletes[i] = new Athlete(name, score);
    }

    sortAthletes(athletes);

    for (int i = 0; i < n; i++) {
      athletes[i].print();
    }
  }

}
