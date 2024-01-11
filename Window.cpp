#include "Window.h"

GameWindow::GameWindow(sf::VideoMode mode, const sf::String& title, sf::Uint32 style)
    : m_title(title)
{
    m_windowedSize = { mode.width, mode.height };
    m_isFullscreen = style == sf::Style::Fullscreen;

    create(mode, title, style);
    setFramerateLimit(70);
    setKeyRepeatEnabled(false);
}

void GameWindow::toggleFullscreen()
{
    if (m_isFullscreen) {
        create(sf::VideoMode(getWindowedSize().x, getWindowedSize().y), m_title, sf::Style::Default);
    }
    else {
        create(sf::VideoMode::getDesktopMode(), m_title, sf::Style::Fullscreen);
    }
    setView(sf::View({ 0.f, 0.f, (float)getSize().x, (float)getSize().y }));
    m_isFullscreen = !m_isFullscreen;
}

void GameWindow::updateWindowedSize()
{
    if (!m_isFullscreen)
    {
        m_windowedSize = getSize();
    }
    setView(sf::View({ 0.f, 0.f, (float)getSize().x, (float)getSize().y }));
}

void GameWindow::setTitle(const sf::String& title)
{
    sf::Window::setTitle(title);
    m_title = title;
}

void GameWindow::setSize(const sf::Vector2u& size)
{
    sf::Window::setSize(size);
    updateWindowedSize();
}

bool GameWindow::isFullscreen() const
{
    return m_isFullscreen;
}

sf::Vector2u GameWindow::getWindowedSize() const
{
    return m_windowedSize;
}

sf::Vector2f GameWindow::getScale() const
{
    return { getSize().x / (float)sf::VideoMode::getDesktopMode().width, getSize().y / (float)sf::VideoMode::getDesktopMode().height };
}

sf::String GameWindow::getTitle() const
{
    return m_title;
}
