import os
import re

dir_path = "/home/user/Code/OpenSource/it-tools-kirigami/src/contents/ui/tools/"
files = [
    "Base64Page.qml",
    "BaseConverterPage.qml",
    "CaseConverterPage.qml",
    "ChmodPage.qml",
    "ColorConverterPage.qml",
    "HashPage.qml",
    "HtmlEntitiesPage.qml",
    "JsonFormatterPage.qml",
    "JsonYamlPage.qml",
    "JwtPage.qml",
    "LoremIpsumPage.qml",
    "MacGeneratorPage.qml",
    "PortGeneratorPage.qml",
    "SlugifyPage.qml",
    "TextStatisticsPage.qml",
    "TokenGeneratorPage.qml",
    "UrlEncoderPage.qml",
    "UuidPage.qml"
]

for filename in files:
    file_path = os.path.join(dir_path, filename)
    with open(file_path, "r") as f:
        content = f.read()

    # Change Kirigami.Page to Kirigami.ScrollablePage
    content = content.replace("Kirigami.Page {", "Kirigami.ScrollablePage {")

    # For ColumnLayout
    # Remove anchors.fill: parent
    content = re.sub(r'ColumnLayout\s*{[^}]*?anchors\.fill:\s*parent', lambda m: m.group(0).replace("anchors.fill: parent", "width: parent.width"), content)
    
    # Remove anchors.margins: Kirigami.Units.largeSpacing (or similar)
    content = re.sub(r'anchors\.margins:\s*Kirigami\.Units\.\w+', '', content)
    
    # Set spacing: Kirigami.Units.largeSpacing
    # If spacing already exists, update it. If not, add it? 
    # Actually, let's just do it carefully.
    
    # Let's try a more robust approach for ColumnLayout properties
    def update_column_layout(match):
        layout_body = match.group(1)
        # Remove unwanted anchors
        layout_body = re.sub(r'anchors\.fill:\s*parent\s*\n?', '', layout_body)
        layout_body = re.sub(r'anchors\.margins:\s*Kirigami\.Units\.\w+\s*\n?', '', layout_body)
        
        # Add or update width
        if "width: parent.width" not in layout_body:
            layout_body = "        width: parent.width\n" + layout_body
        
        # Add or update spacing
        if "spacing:" in layout_body:
            layout_body = re.sub(r'spacing:\s*Kirigami\.Units\.\w+', 'spacing: Kirigami.Units.largeSpacing', layout_body)
        else:
            layout_body = "        spacing: Kirigami.Units.largeSpacing\n" + layout_body
            
        return "    ColumnLayout {\n" + layout_body

    content = re.sub(r'    ColumnLayout\s*{\n(.*?)(?=\n\s*\w+\s*{|\n\s*\w+\s*:)', update_column_layout, content, flags=re.DOTALL)

    # Remove Layout.fillHeight: true from children
    content = re.sub(r'Layout\.fillHeight:\s*true\s*\n?', '', content)
    
    # Remove Item { Layout.fillHeight: true } spacer at the end
    content = re.sub(r'Item\s*{\s*Layout\.fillHeight:\s*true\s*}\s*\n?', '', content)
    
    # Clean up empty lines that might have been left
    content = re.sub(r'\n\s*\n', '\n', content)

    with open(file_path, "w") as f:
        f.write(content)
