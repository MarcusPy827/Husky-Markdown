#include "search_bar.hxx"

SearchBar::SearchBar(QWidget *parent) : QWidget(parent) {
    auto * searchBarLayout = new QHBoxLayout;
    searchBarLayout->setContentsMargins(8, 8, 16, 8);
    searchBarLayout->setSpacing(8);
    setLayout(searchBarLayout);

    searchBox->setObjectName("search_box");
    searchBox->setPlaceholderText(tr("Search \"my notes\""));
    searchBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    searchBox->setFocusPolicy(Qt::ClickFocus);
    searchBarLayout->addWidget(searchBox);

    searchBoxIcon->setParent(this);
    searchBoxIcon->setIconSize(QSize(24, 24));
    searchBoxIcon->move(24, 16);
    searchBoxIcon->setObjectName("search_box_icon");

}