
namespace Applications
{
    partial class TestApplication
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("Earth");
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Mars");
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("Venus");
            System.Windows.Forms.ListViewItem listViewItem4 = new System.Windows.Forms.ListViewItem("Pluto");
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem("Uranus");
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("Mercury");
            System.Windows.Forms.ListViewItem listViewItem7 = new System.Windows.Forms.ListViewItem("Saturn");
            System.Windows.Forms.ListViewItem listViewItem8 = new System.Windows.Forms.ListViewItem("Jupiter");
            System.Windows.Forms.ListViewItem listViewItem9 = new System.Windows.Forms.ListViewItem("Neptune");
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Sun");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Moon");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Earth");
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Mars");
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Solar System", new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3,
            treeNode4});
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Milky Way", new System.Windows.Forms.TreeNode[] {
            treeNode5});
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("Andromeda");
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("Universe", new System.Windows.Forms.TreeNode[] {
            treeNode6,
            treeNode7});
            this.Tabs = new System.Windows.Forms.TabControl();
            this.ButtonTab = new System.Windows.Forms.TabPage();
            this.Button = new System.Windows.Forms.Button();
            this.TextTab = new System.Windows.Forms.TabPage();
            this.TextBox = new System.Windows.Forms.TextBox();
            this.CheckBoxTab = new System.Windows.Forms.TabPage();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.CheckBox = new System.Windows.Forms.CheckBox();
            this.ListViewTab = new System.Windows.Forms.TabPage();
            this.ListView = new System.Windows.Forms.ListView();
            this.NameColumnHeader = new System.Windows.Forms.ColumnHeader();
            this.DataViewTab = new System.Windows.Forms.TabPage();
            this.DataGridView = new System.Windows.Forms.DataGridView();
            this.IdColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.NameColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ViewColumn = new System.Windows.Forms.DataGridViewButtonColumn();
            this.DocumentTab = new System.Windows.Forms.TabPage();
            this.RichTextBox = new System.Windows.Forms.RichTextBox();
            this.TreeTab = new System.Windows.Forms.TabPage();
            this.TreeView = new System.Windows.Forms.TreeView();
            this.SliderTab = new System.Windows.Forms.TabPage();
            this.TrackBar = new System.Windows.Forms.TrackBar();
            this.Tabs.SuspendLayout();
            this.ButtonTab.SuspendLayout();
            this.TextTab.SuspendLayout();
            this.CheckBoxTab.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.ListViewTab.SuspendLayout();
            this.DataViewTab.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.DataGridView)).BeginInit();
            this.DocumentTab.SuspendLayout();
            this.TreeTab.SuspendLayout();
            this.SliderTab.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TrackBar)).BeginInit();
            this.SuspendLayout();
            // 
            // Tabs
            // 
            this.Tabs.Controls.Add(this.ButtonTab);
            this.Tabs.Controls.Add(this.TextTab);
            this.Tabs.Controls.Add(this.CheckBoxTab);
            this.Tabs.Controls.Add(this.ListViewTab);
            this.Tabs.Controls.Add(this.DataViewTab);
            this.Tabs.Controls.Add(this.DocumentTab);
            this.Tabs.Controls.Add(this.TreeTab);
            this.Tabs.Controls.Add(this.SliderTab);
            this.Tabs.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Tabs.Location = new System.Drawing.Point(0, 0);
            this.Tabs.Name = "Tabs";
            this.Tabs.SelectedIndex = 0;
            this.Tabs.Size = new System.Drawing.Size(800, 450);
            this.Tabs.TabIndex = 0;
            // 
            // ButtonTab
            // 
            this.ButtonTab.Controls.Add(this.Button);
            this.ButtonTab.Location = new System.Drawing.Point(4, 24);
            this.ButtonTab.Name = "ButtonTab";
            this.ButtonTab.Size = new System.Drawing.Size(792, 422);
            this.ButtonTab.TabIndex = 5;
            this.ButtonTab.Text = "Button";
            this.ButtonTab.UseVisualStyleBackColor = true;
            // 
            // Button
            // 
            this.Button.Location = new System.Drawing.Point(340, 176);
            this.Button.Margin = new System.Windows.Forms.Padding(0);
            this.Button.Name = "Button";
            this.Button.Size = new System.Drawing.Size(104, 47);
            this.Button.TabIndex = 0;
            this.Button.Text = "Button";
            this.Button.UseVisualStyleBackColor = true;
            // 
            // TextTab
            // 
            this.TextTab.Controls.Add(this.TextBox);
            this.TextTab.Location = new System.Drawing.Point(4, 24);
            this.TextTab.Name = "TextTab";
            this.TextTab.Size = new System.Drawing.Size(792, 422);
            this.TextTab.TabIndex = 3;
            this.TextTab.Text = "Text";
            this.TextTab.UseVisualStyleBackColor = true;
            // 
            // TextBox
            // 
            this.TextBox.Location = new System.Drawing.Point(264, 140);
            this.TextBox.Name = "TextBox";
            this.TextBox.Size = new System.Drawing.Size(228, 23);
            this.TextBox.TabIndex = 0;
            this.TextBox.Text = "Text Box Value";
            // 
            // CheckBoxTab
            // 
            this.CheckBoxTab.Controls.Add(this.trackBar1);
            this.CheckBoxTab.Controls.Add(this.CheckBox);
            this.CheckBoxTab.Location = new System.Drawing.Point(4, 24);
            this.CheckBoxTab.Name = "CheckBoxTab";
            this.CheckBoxTab.Size = new System.Drawing.Size(792, 422);
            this.CheckBoxTab.TabIndex = 4;
            this.CheckBoxTab.Text = "Check Box";
            this.CheckBoxTab.UseVisualStyleBackColor = true;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(305, 306);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(104, 45);
            this.trackBar1.TabIndex = 1;
            // 
            // CheckBox
            // 
            this.CheckBox.AutoSize = true;
            this.CheckBox.Location = new System.Drawing.Point(328, 204);
            this.CheckBox.Name = "CheckBox";
            this.CheckBox.Size = new System.Drawing.Size(82, 19);
            this.CheckBox.TabIndex = 0;
            this.CheckBox.Text = "Check Box";
            this.CheckBox.UseVisualStyleBackColor = true;
            // 
            // ListViewTab
            // 
            this.ListViewTab.Controls.Add(this.ListView);
            this.ListViewTab.Location = new System.Drawing.Point(4, 24);
            this.ListViewTab.Name = "ListViewTab";
            this.ListViewTab.Padding = new System.Windows.Forms.Padding(3);
            this.ListViewTab.Size = new System.Drawing.Size(792, 422);
            this.ListViewTab.TabIndex = 0;
            this.ListViewTab.Text = "List View";
            this.ListViewTab.UseVisualStyleBackColor = true;
            // 
            // ListView
            // 
            this.ListView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.NameColumnHeader});
            this.ListView.GridLines = true;
            this.ListView.HideSelection = false;
            this.ListView.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3,
            listViewItem4,
            listViewItem5,
            listViewItem6,
            listViewItem7,
            listViewItem8,
            listViewItem9});
            this.ListView.Location = new System.Drawing.Point(3, 3);
            this.ListView.Name = "ListView";
            this.ListView.Size = new System.Drawing.Size(786, 111);
            this.ListView.TabIndex = 0;
            this.ListView.UseCompatibleStateImageBehavior = false;
            this.ListView.View = System.Windows.Forms.View.Details;
            // 
            // NameColumnHeader
            // 
            this.NameColumnHeader.Text = "Name";
            // 
            // DataViewTab
            // 
            this.DataViewTab.Controls.Add(this.DataGridView);
            this.DataViewTab.Location = new System.Drawing.Point(4, 24);
            this.DataViewTab.Name = "DataViewTab";
            this.DataViewTab.Padding = new System.Windows.Forms.Padding(3);
            this.DataViewTab.Size = new System.Drawing.Size(792, 422);
            this.DataViewTab.TabIndex = 1;
            this.DataViewTab.Text = "Data View";
            this.DataViewTab.UseVisualStyleBackColor = true;
            // 
            // DataGridView
            // 
            this.DataGridView.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.DataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.IdColumn,
            this.NameColumn,
            this.ViewColumn});
            this.DataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.DataGridView.Location = new System.Drawing.Point(3, 3);
            this.DataGridView.Name = "DataGridView";
            this.DataGridView.RowTemplate.Height = 25;
            this.DataGridView.Size = new System.Drawing.Size(786, 416);
            this.DataGridView.TabIndex = 0;
            // 
            // IdColumn
            // 
            this.IdColumn.HeaderText = "Id";
            this.IdColumn.Name = "IdColumn";
            // 
            // NameColumn
            // 
            this.NameColumn.HeaderText = "Name";
            this.NameColumn.Name = "NameColumn";
            // 
            // ViewColumn
            // 
            this.ViewColumn.HeaderText = "View";
            this.ViewColumn.Name = "ViewColumn";
            // 
            // DocumentTab
            // 
            this.DocumentTab.Controls.Add(this.RichTextBox);
            this.DocumentTab.Location = new System.Drawing.Point(4, 24);
            this.DocumentTab.Name = "DocumentTab";
            this.DocumentTab.Size = new System.Drawing.Size(792, 422);
            this.DocumentTab.TabIndex = 2;
            this.DocumentTab.Text = "Document";
            this.DocumentTab.UseVisualStyleBackColor = true;
            // 
            // RichTextBox
            // 
            this.RichTextBox.Location = new System.Drawing.Point(177, 93);
            this.RichTextBox.Name = "RichTextBox";
            this.RichTextBox.Size = new System.Drawing.Size(360, 179);
            this.RichTextBox.TabIndex = 0;
            this.RichTextBox.Text = "I am a text box with text in it.  ";
            // 
            // TreeTab
            // 
            this.TreeTab.Controls.Add(this.TreeView);
            this.TreeTab.Location = new System.Drawing.Point(4, 24);
            this.TreeTab.Name = "TreeTab";
            this.TreeTab.Size = new System.Drawing.Size(792, 422);
            this.TreeTab.TabIndex = 6;
            this.TreeTab.Text = "Tree";
            this.TreeTab.UseVisualStyleBackColor = true;
            // 
            // TreeView
            // 
            this.TreeView.Location = new System.Drawing.Point(285, 83);
            this.TreeView.Name = "TreeView";
            treeNode1.Name = "Sun";
            treeNode1.Text = "Sun";
            treeNode2.Name = "Moon";
            treeNode2.Text = "Moon";
            treeNode3.Name = "Earth";
            treeNode3.Text = "Earth";
            treeNode4.Name = "Mars";
            treeNode4.Text = "Mars";
            treeNode5.Name = "SolarSystem";
            treeNode5.Text = "Solar System";
            treeNode6.Name = "MilkyWay";
            treeNode6.Text = "Milky Way";
            treeNode7.Name = "Andromeda";
            treeNode7.Text = "Andromeda";
            treeNode8.Name = "Universe";
            treeNode8.Text = "Universe";
            this.TreeView.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode8});
            this.TreeView.Size = new System.Drawing.Size(228, 181);
            this.TreeView.TabIndex = 0;
            // 
            // SliderTab
            // 
            this.SliderTab.Controls.Add(this.TrackBar);
            this.SliderTab.Location = new System.Drawing.Point(4, 24);
            this.SliderTab.Name = "SliderTab";
            this.SliderTab.Padding = new System.Windows.Forms.Padding(3);
            this.SliderTab.Size = new System.Drawing.Size(792, 422);
            this.SliderTab.TabIndex = 7;
            this.SliderTab.Text = "Slider";
            this.SliderTab.UseVisualStyleBackColor = true;
            // 
            // TrackBar
            // 
            this.TrackBar.Location = new System.Drawing.Point(354, 182);
            this.TrackBar.Minimum = 1;
            this.TrackBar.Name = "TrackBar";
            this.TrackBar.Size = new System.Drawing.Size(104, 45);
            this.TrackBar.TabIndex = 0;
            this.TrackBar.TickStyle = System.Windows.Forms.TickStyle.Both;
            this.TrackBar.Value = 1;
            // 
            // TestApplication
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Tabs);
            this.Name = "TestApplication";
            this.Text = "Test Application";
            this.Load += new System.EventHandler(this.Application_Load);
            this.Tabs.ResumeLayout(false);
            this.ButtonTab.ResumeLayout(false);
            this.TextTab.ResumeLayout(false);
            this.TextTab.PerformLayout();
            this.CheckBoxTab.ResumeLayout(false);
            this.CheckBoxTab.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.ListViewTab.ResumeLayout(false);
            this.DataViewTab.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.DataGridView)).EndInit();
            this.DocumentTab.ResumeLayout(false);
            this.TreeTab.ResumeLayout(false);
            this.SliderTab.ResumeLayout(false);
            this.SliderTab.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TrackBar)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl Tabs;
        private System.Windows.Forms.TabPage ListViewTab;
        private System.Windows.Forms.TabPage DataViewTab;
        private System.Windows.Forms.TabPage DocumentTab;
        private System.Windows.Forms.TabPage TextTab;
        private System.Windows.Forms.TabPage CheckBoxTab;
        private System.Windows.Forms.TabPage ButtonTab;
        private System.Windows.Forms.DataGridView DataGridView;
        private System.Windows.Forms.RichTextBox RichTextBox;
        private System.Windows.Forms.TextBox TextBox;
        private System.Windows.Forms.CheckBox CheckBox;
        private System.Windows.Forms.Button Button;
        private System.Windows.Forms.TabPage TreeTab;
        private System.Windows.Forms.TreeView TreeView;
        private System.Windows.Forms.DataGridViewTextBoxColumn IdColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn NameColumn;
        private System.Windows.Forms.DataGridViewButtonColumn ViewColumn;
        private System.Windows.Forms.ColumnHeader NameColumnHeader;
        private System.Windows.Forms.ListView ListView;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.TabPage SliderTab;
        private System.Windows.Forms.TrackBar TrackBar;
    }
}

