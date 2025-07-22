#include "oop.h"
#include <iomanip>
class clsMovie
{
    private:
        string _Title;
        short _Year;
        float _Rating;

    public:
        clsMovie(string Title, short Year, float Rating)
        {
            _Title = Title;
            _Year = Year;
            _Rating = Rating;
        }

        /* copy constructor */

        clsMovie(clsMovie &OldObject)
        {
            _Title = OldObject.MovieTitle();
            _Year = OldObject.MovieYear();
            _Rating = OldObject.MovieRating();
        }

        string MovieTitle(void)
        {
            return (_Title);
        }

        short MovieYear(void)
        {
            return (_Year);
        }

        float MovieRating(void)
        {
            return (_Rating);
        }

        void PrintMovieInfo(void)
        {
            cout << left << setw(20) << _Title;
            cout << "| " << left << setw(10) << _Year;
            cout << "| " << left << setw(10) << _Rating << endl;
        }
};
int main(void)
{
    clsMovie Movie("Gone with the wind", 1939, 8.9);

    clsMovie Movie2 = Movie;

    Movie.PrintMovieInfo();
    Movie2.PrintMovieInfo();

    return (0);
}