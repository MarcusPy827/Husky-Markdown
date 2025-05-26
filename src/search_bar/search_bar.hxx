#ifndef HUSKY_MARKDOWN_SEARCH_BAR_HXX
#define HUSKY_MARKDOWN_SEARCH_BAR_HXX

#include "QWidget"
#include "QHBoxLayout"
#include "QLineEdit"
#include "QPushButton"

class SearchBar : public QWidget {
    Q_OBJECT

    public:
        explicit SearchBar(QWidget *parent = nullptr);
        ~SearchBar() override = default;

    private:
        QLineEdit * searchBox = new QLineEdit;
        QPushButton * searchBoxIcon = new QPushButton;
};


#endif //HUSKY_MARKDOWN_SEARCH_BAR_HXX