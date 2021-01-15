std::shared_ptr<Figure> Factory::figure_create(std::istream& is) {
    std::string name;
    is >> name;
    if ( name == "rectangle" ) {
        return std::shared_ptr<Figure> (new Rectangle(is));
    } else if ( name == "triangle") {
        return std::shared_ptr<Figure> (new Triangle(is));
    } else if ( name == "square") {
        return std::shared_ptr<Figure> (new Square(is));
    } else {
        throw std::logic_error("no such figure");
    }
}

std::shared_ptr<Figure> Factory::figure_create_file(std::ifstream& is) {
    std::string name;
    is >> name;
    if ( name == "rectangle" ) {
        return std::shared_ptr<Figure> (new Rectangle(is));
    } else if ( name == "triangle") {
        return std::shared_ptr<Figure> (new Triangle(is));
    } else if ( name == "square") {
        return std::shared_ptr<Figure> (new Square(is));
    } else {
        throw std::logic_error("no such figure");
    }
}