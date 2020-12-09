#include <string>
#include <vector>
#include <iostream>


class Page
{
  private:
    std::string text;
    /*
      Private variables and methods are only
      accessable by the class own methods.

      here you might place variables and containers(vectors)

      things with private access are
      for exclusively internal use.
    */
  public:
    /*
      Public variables and methods are
      accessible by anyone!

      here you might place getters/setter
      constructors and anything else that
      would need to be called from outside
      the object/class

    */
    // constructor
    Page(std::string Text) : text(Text) {}

    // getter
    std::string getText() { return this->text; }
};
/*
    Encapsulation
        The big idea with OOP is encapsulation.
        encapsulation basically meaning that you
        should protect access and hide any internal
        values or mechanisms.

        Create a black box where the you provide
        the interface that determines how the user
        , uses the object via public methods.

        if you had a logger object with a list
        in it, you'd probably want to encapsulate
        and make the list private.
        Making a method controlling how other objects
        are allowed to interact/manipulate the list.
        So other objects/users calling the object
        would not be to alter the log.
*/
class Chapter
{
    // interval variable and list
    private:
      std::string Title;
      std::vector<Page> pages;
    // interface to interact with private variables
    public:
      // public constructor
      Chapter(std::string newchapterTitle) : Title(newchapterTitle) {}

      std::string getTitle() { return this->Title; }
      void addPage(std:: string pageText) { this->pages.push_back(Page(pageText)); }
      // returns list of strings
      std::vector<std::string> getPages()
      {
          std::vector<std::string> rPages;

          for(Page& page : pages)
            rPages.push_back(page.getText());

          return rPages;
          /*
              returning a list is one way to get around
              not having a nullptr for failing to have
              found a matching object

              others ways:
                Null Object
                std::optional
                struct
                ???
          */
      }
};

class Book
{
  private:
    std::string Title;
    std::string Author;
    std::vector<Chapter> chapters;
  public:
    Book(std::string newTitle, std::string newAuthor)
     : Title(newTitle), Author(newAuthor) {}

    int getNrChapter() { return this->chapters.size() ;}
    Chapter& getChapter(int index) { return this->chapters.at(index); }
    std::string getTitle() { return this->Title; }

    void addChapter(std::string chapterTitle)
    {
      this->chapters.push_back(Chapter(chapterTitle));
    }
};

/*
    Hierarchy
      There's an object hierarchy created in instantiation
      via private variables in the classes.

      Because books has a list of chapters, to access a book chapter
      object you'll have to use book methods
      and the same goes for accessing page objects, which are instantiated
      (created) in the chapter object, through the addPage class method.
      Encapsulating the Page class

      Book
        Title
        Author
        Chapters(vector)
          Chapter
            Title
            Pages(Vector)
              Page
                Text
*/

void libraryInit(std::vector<Book>& Library);

int main()
{
    // declare list of book objects
    std::vector<Book> Library;
    std::string buffer;

    // use constructor to instantiate book and then add it to library
    Library.push_back(Book("Brave New World", "Aldous Huxley"));
    Library.push_back(Book("Fahrenheit 451", "Ray Bradbury"));

    // constructor to initialize book object with a seriously depressing book
    Book theRoad = Book("The Road", "Cormac McCarthy");

    // add said book to library via variable
    Library.push_back(theRoad);

    libraryInit(Library);

    // loop to print books, for loops explained in vectorlabb in labb1.cpp
    for(Book& book : Library)
    {
      for(int index = 0; index < book.getNrChapter() ; index++)
      {
          std::cout << book.getTitle() << '\n';
          auto& chapter = book.getChapter(index);

          std::cout << "Title: " << chapter.getTitle() << '\n';
          for(auto pageText : chapter.getPages())
            std::cout << pageText << '\n';
      }
      std::cout << '\n';
    }
}

// just to declutter main
void libraryInit(std::vector<Book>& Library)
{
  // using a pointer to access the library vector!
  auto bookIter = begin(Library);

  // use -> to access members of pointed to objects
  bookIter->addChapter("Chapter I");
  Chapter& BNWchapter = bookIter->getChapter(0);
  /*
    Turns out you can't reassign references
    once they've been initialized with an object
    they stay bound to that value/object/adress
    for the rest of their lifetime.

    So each chapter needs their own reference
    declaration...
  */
  BNWchapter.addPage(R"(A squat grey building of only thirty-four stories.
Over the entrance the words, CENTRAL LONDON HATCHERY and CONDITIONING
CENTRE, and, in a shield the World State's motto,
COMMUNITY, IDENTITY, STABILITY.)");
  /*
      R"(text)" lets you write a string in raw format.

      a multiline string literal that keeps all newlines
      and others chars
  */

  // iterating iterator/pointer to access next member of vector
  (++bookIter)->addChapter("I. Härden och Salamandern");
  Chapter& F451chapter = bookIter->getChapter(0);

  F451chapter.addPage(R"(Det var ett nöje att bränna.
Det var särskilt roligt att se ting förintas, att se dem svartna och förändras.)");

  (++bookIter)->addChapter("The Road");
  Chapter& Roadchapter = bookIter->getChapter(0);

  Roadchapter.addPage(R"(Nights dark beyond darkness and the days more gray
each one than what gone before.)");
}
