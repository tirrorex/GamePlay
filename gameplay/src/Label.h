#ifndef LABEL_H_
#define LABEL_H_

#include "Control.h"
#include "Theme.h"

namespace gameplay
{

/**
 * A label is the most basic type of control, capable only of rendering text within its border.
 *
 * The following properties are available for labels:

 @verbatim
    label <labelID>
    {
         style       = <styleID>
         alignment   = <Control::Alignment constant> // Note: 'position' will be ignored.
         position    = <x, y>
         autoWidth   = <bool>
         autoHeight  = <bool>
         size        = <width, height>
         width       = <width>   // Can be used in place of 'size', e.g. with 'autoHeight = true'
         height      = <height>  // Can be used in place of 'size', e.g. with 'autoWidth = true'
         text        = <string>
    }
 @endverbatim
 */
class Label : public Control
{
    friend class Container;

public:

    /**
     * Set the text for this label to display.
     *
     * @param text The text to display.
     */
    void setText(const char* text);

    /**
     * Get the text displayed by this label.
     *
     * @return The text displayed by this label.
     */
    const char* getText();

    /**
     * Add a listener to be notified of specific events affecting
     * this control.  Event types can be OR'ed together.
     * E.g. To listen to touch-press and touch-release events,
     * pass <code>Control::Listener::TOUCH | Control::Listener::RELEASE</code>
     * as the second parameter.
     *
     * @param listener The listener to add.
     * @param eventFlags The events to listen for.
     */
    virtual void addListener(Control::Listener* listener, int eventFlags);

protected:

    /**
     * Constructor.
     */
    Label();

    /**
     * Destructor.
     */
    virtual ~Label();

    /**
     * Create a label with a given style and properties.
     *
     * @param style The style to apply to this label.
     * @param properties The properties to set on this label.
     *
     * @return The new label.
     */
    static Label* create(Theme::Style* style, Properties* properties);

    /**
     * Initialize this label.
     */
    virtual void initialize(Theme::Style* style, Properties* properties);

    /**
     * Called when a label's properties change. Updates this label's internal rendering
     * properties, such as its text viewport.
     *
     * @param clip The clipping rectangle of this label's parent container.
     * @param offset The scroll offset of this label's parent container.
     */
    void update(const Rectangle& clip, const Vector2& offset, long elapsedTime);

    /**
     * Draw this label's text.
     *
     * @param clip The clipping rectangle of this label's parent container.
     */
    void drawText(const Rectangle& clip);

    /**
     * The text displayed by this label.
     */
    std::string _text;

    /**
     * The font being used to display the label.
     */
    Font* _font;
    
    /**
     * The text color being used to display the label.
     */
    Vector4 _textColor;
    Rectangle _textBounds;  // The position and size of this control's text area, before clipping.  Used for text alignment.

private:

    /**
     * Constructor.
     */
    Label(const Label& copy);
};

}

#endif