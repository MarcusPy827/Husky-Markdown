#ifndef HUSKY_MARKDOWN_SEARCH_BAR_HXX
#define HUSKY_MARKDOWN_SEARCH_BAR_HXX

#include "QWidget"

class SearchBar : public QWidget {
    Q_OBJECT

    public:
        explicit SearchBar(QWidget *parent = nullptr);
        ~SearchBar() override = default;

    private:

};


#endif //HUSKY_MARKDOWN_SEARCH_BAR_HXX