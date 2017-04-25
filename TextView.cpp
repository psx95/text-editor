#include "TextView.h"

TextView::TextView(const sf::RenderWindow &window)
    : camera(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)),
      deltaScroll(10), deltaRotation(2), deltaZoomIn(0.8f), deltaZoomOut(1.2f) {

    this->content.selectText(0, 12);
    this->content.selectText(100, 120);
}

void TextView::drawLines(sf::RenderWindow &window, TextDocument &document) {
    this->content.drawLines(window, document);
}

// Esta funcion se encarga de transformar las cordenadas de mouse en coordenadas de texto
// TODO: Renombrarla
void TextView::mouseClick(int mouseX, int mouseY) {

    // Consigo el numero de linea usando la coordenada
    // FIX: Errores de redondeo
    int lineN = mouseY / this->content.getLineHeight();
    std::cout << mouseY << "\n";
    std::cout << lineN << "\n";

    // Consigo la posicion del caracter tocado
    // sarasa

    // Eliminar selecciones
    // Mover cursor (setear posicion directamente usando charN y lineN)
    this->content.setCursorPos(lineN, 5);
}

void TextView::setFontSize(int fontSize) {
    this->content.setFontSize(fontSize);
}

// [begin, end] inclusive
void TextView::selectText(int begin, int end) {
    this->content.selectText(begin, end);
}

void TextView::removeSelections() {
    this->content.removeSelections();
}

void TextView::scrollUp() {
    this->camera.move(0, this->deltaScroll);
}

void TextView::scrollDown() {
    this->camera.move(0, -this->deltaScroll);
}

void TextView::scrollLeft() {
    this->camera.move(this->deltaScroll, 0);
}

void TextView::scrollRight() {
    this->camera.move(-this->deltaScroll, 0);
}

void TextView::rotateLeft() {
    this->camera.rotate(this->deltaRotation);
}

void TextView::rotateRight() {
    this->camera.rotate(-this->deltaRotation);
}

void TextView::zoomIn() {
    this->camera.zoom(this->deltaZoomIn);
}

void TextView::zoomOut() {
    this->camera.zoom(this->deltaZoomOut);
}

sf::View TextView::getCameraView() {
    return this->camera;
}
