#ifndef HUSKY_MARKDOWN_NAVIGATION_RAIL_HXX
#define HUSKY_MARKDOWN_NAVIGATION_RAIL_HXX

#include "QWidget"

class NavigationRail : public QWidget {
    Q_OBJECT

    public:
        explicit NavigationRail(QWidget *parent = nullptr);
        ~NavigationRail() override = default;

    private:
};

#endif //HUSKY_MARKDOWN_NAVIGATION_RAIL_HXX