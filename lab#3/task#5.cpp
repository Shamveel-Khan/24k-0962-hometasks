#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    string title;
    Song *next;

    Song(string title) : title(title), next(nullptr) {}
};

class Playlist
{
public:
    Song *head;

    Playlist() : head(nullptr) {}

    void addSong(string title)
    {
        Song *newSong = new Song(title);
        if (!head)
        {
            head = newSong;
            head->next = head;
            return;
        }
        Song *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newSong;
        newSong->next = head;
    }

    void print() const
    {
        if (!head)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song *temp = head;
        do
        {
            cout << temp->title << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }

    void play(int n) const
    {
        if (!head)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song *temp = head;
        for (int i = 0; i < n; i++)
        {
            cout << "Playing: " << temp->title << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    cout << "Playlist: ";
    playlist.print();

    cout << "\nSimulating playback (5 songs):" << endl;
    playlist.play(5);

    return 0;
}
