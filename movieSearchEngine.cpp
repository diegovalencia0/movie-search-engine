#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Video
{

public:
    string id;
    string name;
    string genre;
    int length;
    float rating;
    string comments;

    Video(string i, string n, string g, int l, float r, string c)
    {
        id = i;
        name = n;
        length = l;
        genre = g;
        rating = r;
        comments = c;
    }

    void print()
    {
        cout << setw(10) << id << left << setw(25) << name << left << setw(10) << genre << left << setw(10) << length << left << setw(15) << rating << left << setw(5) << comments << left << endl;
    }

    void display_headline()
    {
        cout << setw(10) << left << "ID" << setw(25) << left << "NAME" << left << setw(10) << "GENRE" << left << setw(10) << "LENGTH" << left << setw(15) << "RAITING" << left << setw(5) << "COMMENTS" << left << endl;
    }

    void display(Video videos[], int size)
    {
        display_headline();
        for (int i = 0; i < size; i++)
        {
            videos[i].print();
        }
    }

    Video search(Video videos[], int size, string search_term)
    {
        for (int i = 0; i < size; i++)
        {
            if (videos[i].name == search_term)
            {
                return videos[i];
            }
        }

        Video placeholder("", "", "", 0, 0, "");
        return placeholder;
    }

    void evaluate(Video videos[], int size, string search_term)
    {
        Video video = search(videos, size, search_term);
    }
};

class Movie : public Video
{
public:
    Movie() : Video("", "", "", 0, 0, "") {}
    Movie(string i, string n, string g, int l, float r, string c)
        : Video(i, n, g, l, r, c) {}

    Video search(Movie movies[], int size)
    {
        string name;

        cout << "Enter movie name: ";
        getline(cin, name);

        return Video::search(movies, size, name);
    }

    void evaluate()
    {
        string name;
        float rating;

        cout << "Enter movie name: ";
        getline(cin, name);

        cout << "Enter your rating for the movie: ";
        cin >> rating;
    }
};

class Serie : public Video
{
public:
    Serie() : Video("", "", "", 0, 0, "") {}
    Serie(string i, string n, string g, int l, float r, string c)
        : Video(i, n, g, l, r, c) {}

    Video search(Serie series[], int size)
    {
        string name;

        cout << "Enter series name: ";
        cin >> name;

        return Video::search(series, size, name);
    }
};

int main()
{
    Video vc("", "", "", 0, 0, "");
    Movie mc("", "", "", 0, 0, "");
    Serie sc("", "", "", 0, 0, "");

    Movie movies[30];
    Serie series[29];

    string row[6];
    string word;
    string line;

    ifstream fm;
    fm.open("movies.csv");

    int i = 0;
    while (getline(fm, line))
    {
        stringstream ss(line);

        int j = 0;
        while (getline(ss, word, ','))
        {
            row[j] = word;
            j++;
        }
        movies[i] =
            Movie(row[0], row[1], row[2], stoi(row[3]), stof(row[4]), row[5]);
        i++;
    }

    fm.close();

    ifstream fs;
    fs.open("series.csv");

    int optionSelected = 0;
    bool validOption = false;

    int k = 0;
    while (getline(fs, line))
    {
        stringstream ss(line);

        int l = 0;
        while (getline(ss, word, ','))
        {
            row[l] = word;
            l++;
        }
        series[k] =
            Serie(row[0], row[1], row[2], stoi(row[3]), stof(row[4]), row[5]);
        k++;
    }

    fs.close();

    //......................Menu of Tecflix......................//
    cout << "Welcome to Teclfix" << endl;

    while (!validOption)
    {
        cout << "Please select an option: " << endl;
        cout << "1. Display all videos" << endl;
        cout << "2. Display all movies" << endl;
        cout << "3.Display all movies by genre" << endl;
        cout << "4. Search movie by name" << endl;
        cout << "5. Evaluate movie between 0-5" << endl;
        cout << "6. Save the changes in the movies file" << endl;
        cout << "7. Display all series" << endl;
        cout << "8. Display series by genre" << endl;
        cout << "9. Search series by ID" << endl;
        cout << "10. Evaluate series between 0-5" << endl;
        cout << "11. Save the changes in the series file" << endl;
        cout << "12. Exit" << endl;
        cin >> optionSelected;

        cin.ignore();

        if (cin.fail() || optionSelected < 1 || optionSelected > 12)
        {
            cin.clear();
            cout << "Invalid option. Please enter a number between 1 and 12." << endl
                 << endl;
        }

        else
        {
            validOption = true;
        }
    }

    //......................Option selected......................//

    if (optionSelected == 1)
    {
        cout << "Here you have all the videos: " << endl;
        cout << endl;
        cout << "Movies" << endl;
        vc.display(movies, 30);
        cout << endl;
        cout << "Series" << endl;
        vc.display(series, 29);
    }
    else if (optionSelected == 2)
    {
        cout << "Here you have all the movies: " << endl;
        vc.display(movies, 30);
    }

    else if (optionSelected == 3)
    {
        cout << "Here you have all the movies by genre: " << endl;
    }

    else if (optionSelected == 4)
    {
        Video m = mc.search(movies, 30);
        m.print();
    }

    else if (optionSelected == 5)
    {
        cout << "Here you can evaluate the movie between 0-5: " << endl;
    }

    else if (optionSelected == 6)
    {
        cout << "Here you can save the changes in the movies file: " << endl;
    }

    else if (optionSelected == 7)
    {
        cout << "Here you have all the series:" << endl;
        vc.display(series, 29);
    }

    else if (optionSelected == 8)
    {
        cout << "Here you have all the series by genre" << endl;
    }

    else if (optionSelected == 9)
    {
        Video s = sc.search(series, 29);
        s.print();
    }

    else if (optionSelected == 10)
    {
        cout << "Here you can evaluate the series between 0-5: " << endl;
    }

    else if (optionSelected == 11)
    {
        cout << "Here you can save the changes in the series file: " << endl;
    }

    else if (optionSelected == 12)
    {
        cout << "Goodbye, see you soon." << endl;
    }

    return 0;
};
