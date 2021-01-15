void Document::print() const {
    if (buffer_.empty()) {
        std::cout << "buffer is empty" << std::endl;
    }
    for (const auto& elem : buffer_) {
        elem->print(std::cout);
    }
}


Document::Document(std::string& newName) {
    name_ = newName;
}


void Document::insert(std::shared_ptr<Figure>& ptr) {
    buffer_.push_back(ptr);
}

void Document::save(const std::string& filename) const {
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        throw std::runtime_error("Can't save to file. No file");
    }
    fout << buffer_.size() << std::endl;
    for (const auto& elem : buffer_) {
        elem->print_file(fout);
    }
}

void Document::load(const std::string& filename) {
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("Cant't load file. No file");
    }
    size_t size;
    fin >> size;
    buffer_.clear();
    for (int i = 0; i < size; ++i) {
        buffer_.push_back(Factory::figure_create_file(fin));
    }
    name_ = filename;
}

std::shared_ptr<Figure> Document::get_figure(size_t index) {
    return buffer_[index];
}

void Document::remove_at(size_t index) {
    if ( index >= buffer_.size()) {
        throw std::out_of_range("out of range");
    }
    buffer_.erase(buffer_.begin() + index);
}

std::string Document::get_name() {
    return this->name_;
}

size_t Document::size() {
    return buffer_.size();
}

void Document::remove_last() {
    if (buffer_.empty()) {
        throw std::logic_error("document is empty");
    }
    buffer_.pop_back();
}

void Document::insert_index(std::shared_ptr<Figure>& newFigure, size_t index) {
    buffer_.insert(buffer_.begin() + index, newFigure);
}