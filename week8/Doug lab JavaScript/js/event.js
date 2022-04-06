function changeColorEvent(event)
{
    // triggerObject looks at the object that triggered this function, which is the button
    // look at the innerHTML to get the title (between the button tags >< Purple in the below example)
    // e.g. <button onclick="changeColorEvent(event);">Purple</button>
    // convert that title string into lowercase because that's required
    // then use that as the background colour
    var triggerObject = event.srcElement;
    document.getElementById('colorDiv').style.backgroundColor = triggerObject.innerHTML.toLowerCase()
}