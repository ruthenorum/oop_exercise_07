void InsertCommand::unexecute() {
    doc_->remove_last();
}

InsertCommand::InsertCommand(std::shared_ptr<Document> &doc) {
    doc_ = doc;
}

RemoveCommand::RemoveCommand(std::shared_ptr<Figure> &newFigure, size_t newIndex, std::shared_ptr<Document> &doc) {
    doc_ = doc;
    figure_ = newFigure;
    index_ = newIndex;
}

void RemoveCommand::unexecute() {
    doc_->insert_index(figure_,index_);
}
