$(document).ready(function () {

    $('#add-task-btn').on("click", function () {
        let taskText = $("#new-task").val();
        let taskItem = `<li>
                            <span class="task">${taskText}</span>
                            <button class="delete-btn">Delete</button>
                        </li>`;
        $('#task-list').append(taskItem);
        $("#new-task").val("");
        
    });

    $("#task-list").on("click", ".task",function () {
        $(this).closest("li").toggleClass("completed");
    });

    $("#task-list").on("click", ".delete-btn", function () {
        $(this).closest("li").remove();

    })

});