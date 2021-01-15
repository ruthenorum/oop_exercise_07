Editor::Editor() {
    doc_ = nullptr;
}

void Editor::print_document() {
    if (doc_ == nullptr) {
        std::cout << "no document" << std::endl;
        return;
    }
    doc_->print();
}

void Editor::create_document(std::string& newName) {
    doc_ = std::make_shared<Document>(newName);
}

void Editor::insert_in_document(std::shared_ptr<Figure>& newFigure) {
    if (doc_ == nullptr) {
        std::cout << "no document" << std::endl;
        return;
    }
    std::shared_ptr<ICommand> command = std::shared_ptr<ICommand>(new InsertCommand(doc_));
    doc_->insert(newFigure);
    history_.push(command);
}

void Editor::delete_in_document(size_t index) {
    if (doc_ == nullptr) {
        std::cout << "no document" << std::endl;
        return;
    }
    if (index >= doc_->size()) {
        std::cout << "out of range" << std::endl;
        return;
    }
    std::shared_ptr<Figure> tmp = doc_->get_figure(index);
    std::shared_ptr<ICommand> command = std::shared_ptr<ICommand>(new RemoveCommand(tmp,index,doc_));
    doc_->remove_at(index);
    history_.push(command);
}

void Editor::save_document() {
    if (doc_ == nullptr) {
        std::cout << "no document" << std::endl;
        return;
    }
    std::string saveName = doc_->get_name();
    doc_ ->save(saveName);
}

void Editor::load_document(std::string& name) {
    doc_ = std::make_shared<Document>(name);
    doc_->load(name);
    while (!history_.empty()){
        history_.pop();
    }
}

void Editor::undo() {
    if (history_.empty()) {
        throw std::logic_error("history is empty");
    }
    std::shared_ptr<ICommand> lastCommand = history_.top();
    lastCommand->unexecute();
    history_.pop();
}